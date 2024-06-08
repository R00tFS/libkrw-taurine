TARGET = libkrw-plugin.dylib
CC = clang

CFLAGS = -Iinclude/ -isysroot $(shell xcrun --sdk iphoneos --show-sdk-path) -arch arm64 -arch arm64e -miphoneos-version-min=14.0 -fobjc-arc -O3 -fvisibility=hidden
LDFLAGS = -dynamiclib -rpath /

all: $(TARGET) sign

sign: $(TARGET)
	@ldid -S $^

$(TARGET): $(wildcard src/*.c src/libkernrw/*.c)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	@rm -f $(TARGET)
	@rm -f libkrw-plugin.deb
    
package: all
	@mkdir -p .package/DEBIAN
	@mkdir -p .package/usr/lib/libkrw
	@cp control .package/DEBIAN/control
	@cp $(TARGET) .package/usr/lib/libkrw/$(TARGET)
	dpkg-deb --root-owner-group -Zzstd -b .package ./libkrw-plugin.deb
	@rm -rf .package
