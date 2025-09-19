class Spreadsheet(object):

    def __init__(self, rows):
        self.mpp = {}

    def setCell(self, cell, value):
        self.mpp[cell] = value

    def resetCell(self, cell):
        self.mpp[cell] = 0

    def getValue(self, formula):
        formula = formula[1:]
        for i in range(len(formula)):
            if formula[i] == '+':
                s1, s2 = formula[:i], formula[i+1:]
                left = self.mpp.get(s1, 0) if s1[0].isupper() else int(s1)
                right = self.mpp.get(s2, 0) if s2[0].isupper() else int(s2)
                return left + right
        return 0