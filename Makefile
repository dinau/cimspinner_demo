all:
	$(MAKE) -C demo/c
	$(MAKE) -C demo/cpp

.PHONEY: gen run format clean

gen:
	ruby genCImSpinner.rb

run:
	$(MAKE) -C demo/c run

format:
	$(MAKE) -C demo/c format

clean:
	$(MAKE) -C demo/c   clean
	$(MAKE) -C demo/cpp clean
