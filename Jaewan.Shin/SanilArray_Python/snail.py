import sys


class SnailArray:

	__sizeX = 5
	__sizeY = 5

	def __init__(self, x, y):
		self.__sizeX = x
		self.__sizeY = y

		self.__snail =  [[self.__sizeX] * self.__sizeX for x in range(self.__sizeY) ]

		self.__move_cnt_x = self.__sizeX + 1
		self.__move_cnt_y = self.__sizeY
		self.__current_pos = 1 	# 0:X | 1:Y

		self.__direction = 0 	# 0:up | 1:right | 2:down | 3: left

	def __getNextMoveCnt(self):

		if self.__current_pos == 1:
			self.__current_pos = 0
			self.__move_cnt_x -= 1
			return self.__move_cnt_x
		else:
			self.__current_pos = 1
			self.__move_cnt_y -= 1
			return self.__move_cnt_y

	def __getNextDirection(self):

		self.__direction += 1
		if self.__direction == 4:
			self.__direction = 0
		return self.__direction

	def getSanilArray(self):

		pos_x = 0
		pos_y = 0
		move_cnt = 0
		total_cnt = (self.__sizeX*self.__sizeY)

		while move_cnt != total_cnt:
			cnt = self.__getNextMoveCnt()
			__direction = self.__getNextDirection()

			for i in range(0, cnt):
				move_cnt += 1
				if __direction == 0:
					self.__snail[pos_y][pos_x] = move_cnt
					pos_y -= 1
				elif __direction == 1:
					self.__snail[pos_y][pos_x] = move_cnt
					pos_x += 1
				elif __direction == 2:
					self.__snail[pos_y][pos_x] = move_cnt
					pos_y += 1
				elif __direction == 3:	
					self.__snail[pos_y][pos_x] = move_cnt
					pos_x -= 1
				else:
					print "error"

			if __direction == 0:
				pos_y += 1
				pos_x += 1
			elif __direction == 1:
				pos_x -= 1
				pos_y += 1
			elif __direction == 2:
				pos_x -= 1
				pos_y -= 1
			elif __direction == 3:	
				pos_x += 1
				pos_y -= 1
			else:
				print "error"
		return self.__snail


def main(args):
	if len(args) < 3:
		print "ex) python snail.py [number] [number]"
		print "    python snail.py 5 5"
		return

	x = int(args[1])
	y =  int(args[2])
	snail = SnailArray(x, y)
	snailArray = snail.getSanilArray()
	for n in range(0, y):
		print snailArray[n] 

main(sys.argv)
