#!/usr/bin/python

<<<<<<< HEAD
fd = file('refman.tex', 'r')
fd2 = file('filelist.tex', 'w')
=======
fd = file('refman.tex','r')
fd2 = file('filelist.tex','w')
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

line = fd.readline()
while line.find('Module Index') < 0:
    line = fd.readline()

fd2.write(line)
<<<<<<< HEAD
line = fd.readline()

while line.find('printindex') < 0:
    fd2.write(line)
    line = fd.readline()

=======
line=fd.readline()

while line.find('printindex') < 0:
    fd2.write(line)
    line=fd.readline()
    
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
fd.close()
fd2.close()
