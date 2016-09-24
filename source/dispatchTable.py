# dispatchTable.py

dispTable={
  "+": (lambda x, y: x+y),
  "-": (lambda x, y: x-y),  
  "*": (lambda x, y: x*y),
  "/": (lambda x, y: x/y)
}

print

print "3.5+4.5= ", dispTable['+'](3.5, 4.5)
print "3.5-4.5= ", dispTable['-'](3.5, 4.5)
print "3.5*4.5= ", dispTable['*'](3.5, 4.5)
print "3.5/4.5= ", dispTable['/'](3.5, 4.5)

dispTable['^']= lambda x, y: pow(x,y)
print "3.5^4.5= ", dispTable['^'](3.5, 4.5)

print

