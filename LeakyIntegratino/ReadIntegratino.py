import serial
import numpy as np
import pylab as pl

devAdd = '/dev/ttyACM0'
baudrate = 9600

integratino = serial.Serial(devAdd, baudrate)
dt = 0.01

length = 1000
Vhist = np.zeros( (length,1) )
t = np.array( range(length) )*dt
Ihist = np.zeros( (length,1) )

# Plotting
pl.figure()
pl.ion()

pl.ylim([-0.1,2.1])
pl.xlim([0,t[-1]])

pl.plot([-10,t[-1]+10], [1.0,1.0], 'g--')

pl.xlabel('time (ms)')
pl.ylabel('Membrane potential (a.u.)')

line, = pl.plot(t, Vhist, 'r-', linewidth=2.0)
pl.draw()


while 1:
    integratino.flush()
    r = integratino.readline()
    var = r.split('\n')[0].split('\r')[0].split(' ')
    
    if len(var) == 3 :
        # Shuffling
        Vhist[:-1] = Vhist[1:]
        Ihist[:-1] = Ihist[1:]
        
        # Updating
        Ihist[-1] = float(var[1])
        Vhist[-1] = float(var[2])
        
        line.set_ydata(Vhist)
        pl.draw()
    
