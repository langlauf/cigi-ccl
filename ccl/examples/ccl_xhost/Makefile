OBJS=\
	Callbacks.o\
	CigiExample.o\
	ExampleIO.o\
	GenProc.o\
	HostMan.o\
	Network.o\
	ParseLine.o\
	ParseValue.o\
	XAerosolResp.o\
	XAnimationStop.o\
	XCollDetSegResp.o\
	XCollDetVolResp.o\
	XEventNotification.o\
	XHatHotResp.o\
	XHatHotXResp.o\
	XIGMsg.o\
	XLosResp.o\
	XLosXResp.o\
	XMaritimeSurfaceResp.o\
	XPositionResp.o\
	XSOF.o\
	XSensorResp.o\
	XSensorXResp.o\
	XTerrestrialSurfaceResp.o\
	XWeatherCondResp.o

CXXFLAGS=`pkg-config --cflags cigicl`
LDFLAGS=`pkg-config --libs cigicl`

all: ccl_xhost

ccl_xhost: $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS) 

