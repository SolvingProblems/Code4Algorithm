# Class: AccountBalance
# Method: processTransactions
# Parameters: integer, tuple (string)
# Returns: integer
# Method signature: def processTransactions(self, startingBalance, transactions):

class AccountBalance:
    def processTransactions(self, startingBalance, transactions):

        balance = int(startingBalance)
        for tran in transactions:
            cond = tran.split(' ')[0]
            value = int(tran.split(' ')[1])

            if cond == "D":
                balance = balance - value
            elif cond == "C":
                balance = balance + value
            else:
                return ""

        return balance



ab = AccountBalance();
print ab.processTransactions(100, {"C 1000", "D 500", "D 350"})

# 100
# {"C 1000", "D 500", "D 350"}
# Returns: 250
# With no transactions, the balance doesn't change by the end of the day.

# 2)
# 100
# {"D 50", "D 20", "D 40"}
# Returns: -10
# Uh oh! This person's account is overdrawn.

# 3)
# 53874
# {"D 1234", "C 987", "D 2345", "C 654", "D 6789", "D 34567"}
# Returns: 10580
# Several transactions of both types.