FROM wiiulegacy/core:0.1

RUN rm -rf $DEVKITPRO/portlibs
COPY --from=wiiulegacy/dynamic_libs:0.1 $DEVKITPRO/portlibs $DEVKITPRO/portlibs

RUN git clone https://github.com/Maschell/libutils -b master
WORKDIR libutils
RUN git checkout v0.1

RUN make && make install

WORKDIR ..
RUN rm -rf libutils