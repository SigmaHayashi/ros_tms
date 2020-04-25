<<<<<<< HEAD
# mbedRPC.py - mbed RPC interface for Python
#
# Copyright (c) 2010 ARM Ltd
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
# Example:
=======
#mbedRPC.py - mbed RPC interface for Python
#
##Copyright (c) 2010 ARM Ltd
##
##Permission is hereby granted, free of charge, to any person obtaining a copy
##of this software and associated documentation files (the "Software"), to deal
##in the Software without restriction, including without limitation the rights
##to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
##copies of the Software, and to permit persons to whom the Software is
##furnished to do so, subject to the following conditions:
## 
##The above copyright notice and this permission notice shall be included in
##all copies or substantial portions of the Software.
## 
##THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
##IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
##FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
##AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
##LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
##OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
##THE SOFTWARE.
#
#Example:
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#>from mbedRPC import*
#>mbed = SerialRPC("COM5",9600);
#>myled = DigitalOut(LED1);
#>myled.write(1)
<<<<<<< HEAD
#>

import serial
import urllib2
import time


class pin():

=======
#> 

import serial, urllib2, time

class pin():
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        def __init__(self, id):
                self.name = id

LED1 = pin("LED1")
LED2 = pin("LED2")
LED3 = pin("LED3")
LED4 = pin("LED4")

p5 = pin("p5")
p6 = pin("p6")
p7 = pin("p7")
p8 = pin("p8")
p9 = pin("p9")
p10 = pin("p10")
p11 = pin("p11")
p12 = pin("p12")
p13 = pin("p13")
p14 = pin("p14")
p15 = pin("p15")
p16 = pin("p16")
p17 = pin("p17")
p18 = pin("p18")
p19 = pin("p19")
p20 = pin("p20")
p21 = pin("p21")
p22 = pin("p22")
p23 = pin("p23")
p24 = pin("p24")
p25 = pin("p25")
p26 = pin("p26")
p27 = pin("p27")
p28 = pin("p28")
p29 = pin("p29")
p30 = pin("p30")


<<<<<<< HEAD
# mbed super class
class mbed:

    def __init__(self):
            print("This will work as a demo but no transport mechanism has been selected")

    def rpc(self, name, method, args):
            print("Superclass method not overridden")

# Transport mechanisms, derived from mbed


class SerialRPC(mbed):

    def __init__(self, port, baud):
        self.ser = serial.Serial(port)
        self.ser.setBaudrate(baud)

=======
#mbed super class
class mbed:
    def __init__(self):
            print("This will work as a demo but no transport mechanism has been selected")
        
    def rpc(self, name, method, args):
            print("Superclass method not overridden")

#Transport mechanisms, derived from mbed

class SerialRPC(mbed):

    def __init__(self,port, baud):
        self.ser = serial.Serial(port)
        self.ser.setBaudrate(baud)


>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        def rpc(self, name, method, args):
                self.ser.write("/" + name + "/" + method + " " + " ".join(args) + "\n")
                return self.ser.readline().strip()

<<<<<<< HEAD

=======
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
class HTTPRPC(mbed):

    def __init__(self, ip):
        self.host = "http://" + ip

    def rpc(self, name, method, args):
        response = urllib2.urlopen(self.host + "/rpc/" + name + "/" + method + "," + ",".join(args))
        return response.read().strip()


<<<<<<< HEAD
# mbed Interfaces

class DigitalOut():

    def __init__(self, this_mbed, mpin):
=======
#mbed Interfaces

class DigitalOut():

    def __init__(self, this_mbed , mpin):
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        self.mbed = this_mbed
        if isinstance(mpin, str):
            self.name = mpin
        elif isinstance(mpin, pin):
            self.name = self.mbed.rpc("DigitalOut", "new", [mpin.name])
<<<<<<< HEAD

=======
 
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    def __del__(self):
        r = self.mbed.rpc(self.name, "delete", [])

    def write(self, value):
        r = self.mbed.rpc(self.name, "write", [str(value)])

    def read(self):
        r = self.mbed.rpc(self.name, "read", [])
        return int(r)
<<<<<<< HEAD


class AnalogIn():

    def __init__(self, this_mbed, mpin):
=======
      
class AnalogIn():

    def __init__(self, this_mbed , mpin):
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        self.mbed = this_mbed
        if isinstance(mpin, str):
            self.name = mpin
        elif isinstance(mpin, pin):
            self.name = self.mbed.rpc("AnalogIn", "new", [mpin.name])

    def __del__(self):
        r = self.mbed.rpc(self.name, "delete", [])
<<<<<<< HEAD

=======
        
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    def read(self):
        r = self.mbed.rpc(self.name, "read", [])
        return float(r)

    def read_u16(self):
        r = self.mbed.rpc(self.name, "read_u16", [])
        return int(r)

<<<<<<< HEAD

class AnalogOut():

    def __init__(self, this_mbed, mpin):
=======
class AnalogOut():

    def __init__(self, this_mbed , mpin):
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        self.mbed = this_mbed
        if isinstance(mpin, str):
            self.name = mpin
        elif isinstance(mpin, pin):
            self.name = self.mbed.rpc("AnalogOut", "new", [mpin.name])

    def __del__(self):
        r = self.mbed.rpc(self.name, "delete", [])

    def write(self, value):
        r = self.mbed.rpc(self.name, "write", [str(value)])

    def write_u16(self, value):
        r = self.mbed.rpc(self.name, "write_u16", [str(value)])

    def read(self):
        r = self.mbed.rpc(self.name, "read", [])
        return float(r)

<<<<<<< HEAD

class DigitalIn():

    def __init__(self, this_mbed, mpin):
=======
class DigitalIn():

    def __init__(self, this_mbed , mpin):
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        self.mbed = this_mbed
        if isinstance(mpin, str):
            self.name = mpin
        elif isinstance(mpin, pin):
            self.name = self.mbed.rpc("DigitalIn", "new", [mpin.name])

    def __del__(self):
        r = self.mbed.rpc(self.name, "delete", [])

    def read(self):
        r = self.mbed.rpc(self.name, "read", [])
        return int(r)

<<<<<<< HEAD

class PwmOut():

    def __init__(self, this_mbed, mpin):
=======
class PwmOut():
    
    def __init__(self, this_mbed , mpin):
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        self.mbed = this_mbed
        if isinstance(mpin, str):
            self.name = mpin
        elif isinstance(mpin, pin):
            self.name = self.mbed.rpc("PwmOut", "new", [mpin.name])

    def __del__(self):
        r = self.mbed.rpc(self.name, "delete", [])

    def write(self, value):
        r = self.mbed.rpc(self.name, "write", [str(value)])

    def read(self):
        r = self.mbed.rpc(self.name, "read", [])
        return float(r)

    def period(self, value):
        r = self.mbed.rpc(self.name, "period", [str(value)])
<<<<<<< HEAD

=======
        
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    def period_ms(self, value):
        r = self.mbed.rpc(self.name, "period_ms", [str(value)])

    def period_us(self, value):
        r = self.mbed.rpc(self.name, "period_us", [str(value)])
<<<<<<< HEAD

    def puslewidth(self, value):
        r = self.mbed.rpc(self.name, "pulsewidth", [str(value)])

=======
        
    def puslewidth(self, value):
        r = self.mbed.rpc(self.name, "pulsewidth", [str(value)])
        
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    def puslewidth_ms(self, value):
        r = self.mbed.rpc(self.name, "pulsewidth_ms", [str(value)])

    def puslewidth_us(self, value):
        r = self.mbed.rpc(self.name, "pulsewidth_us", [str(value)])

<<<<<<< HEAD

class Serial():

    def __init__(self, this_mbed, tx, rx=""):
=======
class Serial():
        
    def __init__(self, this_mbed , tx, rx = ""):
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        self.mbed = this_mbed
        if isinstance(tx, str):
            self.name = mpin
        elif isinstance(mpin, pin):
            self.name = self.mbed.rpc("Serial", "new", [tx.name, rx.name])
<<<<<<< HEAD

=======
             
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    def __del__(self):
        r = self.mbed.rpc(self.name, "delete", [])

    def putc(self, value):
        r = self.mbed.rpc(self.name, "putc", [str(value)])

    def puts(self, value):
<<<<<<< HEAD
        r = self.mbed.rpc(self.name, "puts", ["\"" + str(value) + "\""])
=======
        r = self.mbed.rpc(self.name, "puts", [ "\"" + str(value) + "\""])
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

    def getc(self):
        r = self.mbed.rpc(self.name, "getc", [])
        return int(r)

<<<<<<< HEAD

class RPCFunction():

    def __init__(self, this_mbed, name):
=======
class RPCFunction():

    def __init__(self, this_mbed , name):
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        self.mbed = this_mbed
        if isinstance(name, str):
            self.name = name

    def __del__(self):
        r = self.mbed.rpc(self.name, "delete", [])

    def read(self):
        r = self.mbed.rpc(self.name, "read", [])
        return int(r)

    def run(self, input):
        r = self.mbed.rpc(self.name, "run", [input])
        return r

<<<<<<< HEAD

class RPCVariable():

    def __init__(self, this_mbed, name):
=======
class RPCVariable():

    def __init__(self, this_mbed , name):
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        self.mbed = this_mbed
        if isinstance(name, str):
            self.name = name

    def __del__(self):
        r = self.mbed.rpc(self.name, "delete", [])

    def write(self, value):
        self.mbed.rpc(self.name, "write", [str(value)])

    def read(self):
        r = self.mbed.rpc(self.name, "read", [])
        return r

<<<<<<< HEAD

=======
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
def wait(s):
    time.sleep(s)
