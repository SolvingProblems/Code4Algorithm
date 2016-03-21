STATICLIB = BigInteger.a

$(STATICLIB): BigInteger.o
	ar rcs $@ $^

BigInteger.o: BigInteger.cpp
	g++ -std=c++11 -c $<

clean:
	rm *.o
	rm *.a
