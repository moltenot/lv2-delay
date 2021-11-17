BUNDLE_NAME=delay.lv2
UTILS_DIR=dsp-utils
INSTALLDIR=~/.lv2/
FUNC_OB=$(UTILS_DIR)/functions.o

.PHONY: clean reinstall

$(FUNC_OB):
	$(MAKE) -C $(UTILS_DIR)

delay.so: $(FUNC_OB)
	g++ -o delay.so  -shared -fPIC -DPIC delay.cpp $(FUNC_OB) `pkg-config --cflags --libs lv2-plugin fftw3 fftw3f`

bundle:	delay.so
	mkdir -p $(BUNDLE_NAME)
	mv delay.so $(BUNDLE_NAME)
	cp manifest.ttl delay.ttl $(BUNDLE_NAME)

clean:
	rm -f delay.so 
	rm -rf $(BUNDLE_NAME)
	rm circ_buf.o
	rm test_buf

install: bundle
	mv $(BUNDLE_NAME) $(INSTALLDIR)

uninstall:
	rm -rf $(INSTALLDIR)/$(BUNDLE_NAME)

reinstall: uninstall install

test:
	jalv https://github.com/moltenot/lv2-delay

test_buf:
	g++ -o test_buf test_buf.cpp circular_buffer.cpp -Wall 
	./test_buf