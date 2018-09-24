FROM wiiulegacy/core:0.1

MAINTAINER Maschell <maschell@gmx.de>

COPY --from=wiiulegacy/dynamic_libs:0.1 /artifacts $DEVKITPRO/portlibs

RUN git clone https://github.com/Maschell/libutils -b master && cd libutils && git checkout v0.1

WORKDIR libutils

RUN make && \
	find $DEVKITPRO/portlibs -maxdepth 3 -type f -delete && \
	make install && \
	cp -r ${DEVKITPRO}/portlibs /artifacts

WORKDIR /artifacts
