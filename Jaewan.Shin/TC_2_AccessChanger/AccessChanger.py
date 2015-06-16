# TopCoder
# Class: AccessChanger
# Method: convert
# Parameters: tuple (string)
# Returns: tuple (string)
# Method signature: def convert(self, program):


class AccessChanger:
    def convert(self, program):

        tempProgram = list(program)
        newProgram = []
        for str in tempProgram:
            front = 0
            newStr = ""

            for idx in range(0, len(str)-1):
                if str[idx] == '-' and str[idx+1] == '>':
                    newStr += str[front:idx] + "."
                    front = idx + 2

                if str[idx] == '/' and str[idx+1] == '/':
                    newStr += str[front:]
                    front = len(str)
                    break;

            newStr += str[front:]
            newProgram.append(newStr)
        return tuple(newProgram)


ac = AccessChanger();

data1 = ("Test* t = new Test();", "t->a = 1;", "t->b = 2;", "t->go(); // a=1, b=2 --> a=2, b=3")
print ac.convert(data1)
# Returns: {"Test* t = new Test();", "t.a = 1;", "t.b = 2;", "t.go(); // a=1, b=2 --> a=2, b=3" }
data2 = ("---> // the arrow --->", "---", "> // the parted arrow")
print ac.convert(data2)
# Returns: {"--. // the arrow --->", "---", "> // the parted arrow" }
data3 = ("->-> // two successive arrows ->->",)
print ac.convert(data3)
# Returns: {".. // two successive arrows ->->" }

