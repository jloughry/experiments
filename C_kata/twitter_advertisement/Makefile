target = twitter_advertisement

CC = gcc

CFLAGS = -Wall -Wextra

$(target): $(target).c
	$(CC) $(CFLAGS) -o $(target) $<
	mv $(target).exe $(target)

clean:
	rm -f $(target)

