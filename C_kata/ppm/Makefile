generate_gradient = gradient
gradient_file = red-green_gradient.ppm

executables = $(generate_gradient)
generated_files = $(gradient_file)

all: $(generate_gradient)

$(generate_gradient): $(generate_gradient).c
	gcc -Wall -Werror -pedantic -o $@ $<
	mv $@.exe $@

test:
	./$(generate_gradient) > $(gradient_file)

clean:
	rm -fv $(executables) $(generated_files)

