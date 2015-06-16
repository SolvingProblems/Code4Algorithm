
import sys

class PrimeNPalindroms:

	def __init__(self, num):
		self.__num = num

	def isPrimeNumber(self):

		if self.__num == 1 or self.__num == 2:
			return True

		maxNum = int(self.__num**0.5)

		cnt = 0
		for i in range(2, maxNum+1):
			remainder = self.__num % i
			if remainder == 0:
				return False

		return True

	def isPalindrome(self):
		strNum = str(self.__num)
		strLen = len(strNum)

		leftPos = 0
		rightPos = strLen-1
		for i in range(0, int(strLen/2)):

			# print leftPos, strNum[leftPos] 
			if strNum[leftPos] != strNum[rightPos]:
				return False
			leftPos += 1
			rightPos -= 1

		return True


# prime number 798823117
def main(args):
	if len(args) < 2:
		print "ex) python prime_palindromes.py [number]"
		print "    python prime_palindromes.py 798823117"
		print "    python prime_palindromes.py 12321"
		return

	num = int(args[1])

	pNp = PrimeNPalindroms(num)
	isPrime = pNp.isPrimeNumber();

	str = "prime number"
	if isPrime:
		str = args[1] + " is a " + str
	else:
		str = args[1] + " is not a " + str
	print str
 
	isPalindrome = pNp.isPalindrome();
	str = "palindrome"
	if isPalindrome:
		str = args[1] + " is a " + str
	else:
		str = args[1] + " is not a " + str
	print str

	# while True:
	# 	num += 1
	# 	pNp = PrimeNPalindroms(num)

	# 	isPalindromeByStr = pNp.isPalindrome()
	# 	if isPalindromeByStr == False:
	# 		continue	

	# 	isPrime = pNp.isPrimeNumber()
	# 	if isPrime == False:
	# 		continue
	# 	break

	# print num



main(sys.argv)