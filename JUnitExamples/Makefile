JFLAGS = -g
JC = javac
# .SUFFIXES: .java .class
# .java.class:
# 	$(JC) $(JFLAGS) $*.java

# CLASSES = \
#     Node.java

default: test

test:
	$(JC) -cp /usr/share/java/junit4.jar TestBasic.java
	java -cp /usr/share/java/junit4.jar:. org.junit.runner.JUnitCore TestBasic 

# classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class