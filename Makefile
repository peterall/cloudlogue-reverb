TOPTARGETS := all

PLATFORMS := prologue minilogue-xd nutekt-digital

VERSION=1.0-0
PACKAGE = cloudlogue-reverb-$(VERSION).zip

$(TOPTARGETS): $(PLATFORMS) package

clean:
	@echo Cleaning ./build and packages
	@rm -fR .dep ./build
	@rm -f cloudlogue-reverb.*unit
	@rm -f cloudlogue-reverb-*.zip

$(PLATFORMS):
	@PLATFORM=$@ VERSION=$(VERSION) $(MAKE) -f cloudlogue-reverb.mk $(MAKECMDGOALS)

package:
	@echo Packaging to ./${PACKAGE}
	@zip -q9 - *.*unit credits.txt > ${PACKAGE}
	@echo All done