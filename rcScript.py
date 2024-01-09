import subprocess
import matplotlib.pyplot as plt
import matplotlib.ticker as tick
import re

# a function to rewrite a file (to a new file), with a change in one (or more) lines.
def replaceParam(old_path,new_path,old_param,new_param):
    with open(old_path) as orig_script: # open the original script for reading
        with open(new_path, "w") as iter_script: # open the new script for writing
            for line in orig_script:
                if re.search(old_param, line): # find the original parameter
                    line = re.sub(old_param, new_param, line) # replace it with the new parameter
                iter_script.write(line) # write the (changed) lines to the new file

# function to extract results from the "<script>.measure" file by the measurement name
def extractMeasurement(path,meas):
    with open(path + ".measure") as iter_script: # open the measurements file
        for line in iter_script:
            if re.search(meas, line): # fine the line of the measurement by its name
                param_line = line.split("=") # split the line with "=" as the delimiter
                param = param_line[1].split() # take the value, and delete all white spaces
                param = float(param[0]) # convert the value to a floating number
                return param
            
# function to generate a range for a parameter sweep
def my_range(start, stop, step):
    while start <= stop:
        yield start # return the current value in the sweep
        start += step



# Time constant of the RC circuit for Capacitance sweep
# from 0.1uF to 0.5uF with steps of 0.1uF
print("Simple RC Circuit - TAU vs C1 Simulation Start")
with open("spectre.log", "w") as logFile: # Create an empty log file for the run
    logFile.write("")
i = 0
cap = [] # capacitance values (x vector)
tau = [] # time constant values (y vector)
for value in my_range(0.1, 0.5, 0.1):
    # replace the "vdd" parameter
    replaceParam("rc.cir","rci.cir","C1 N2 0 1u","C1 N2 0 " + str(value) + "u")
    # run the simulation. The simulation details will be written to the "spectre.log" file
    with open("spectre.log", "a") as logFile:
        subprocess.call("spectre rci.cir", shell=True, stdout=logFile, stderr=logFile)
    tau.append(extractMeasurement("rci", "tau")) # extract tau
    cap.append(value) # add the value to the capacitance vector
    print("Value " + str(value) + " Done.") # just an output so we’ll know the state
    i += 1

# print the x and y vectors
for x,y in zip(cap,tau):
    print(str(x) + "uF" + " : " + str(y) + "s")

# plot the results
plt.figure(1)
plt.plot(cap,tau)
plt.xlabel("C1 [micro F]")
plt.ylabel("Time Constant [sec]")
plt.title("RC Circuit Time Constant as a function of Capacitance")
plt.savefig("tauvsc.pdf")
plt.show()

