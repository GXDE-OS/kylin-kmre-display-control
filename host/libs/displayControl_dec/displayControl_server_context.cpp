// Generated Code - DO NOT EDIT !!
// generated by 'emugen'


#include <string.h>
#include "displayControl_server_context.h"


#include <stdio.h>

int displayControl_server_context_t::initDispatchByName(void *(*getProc)(const char *, void *userData), void *userData)
{
	FBPost = (FBPost_server_proc_t) getProc("FBPost", userData);
	postLayer = (postLayer_server_proc_t) getProc("postLayer", userData);
	postAllLayersDone = (postAllLayersDone_server_proc_t) getProc("postAllLayersDone", userData);
	getDisplayWidth = (getDisplayWidth_server_proc_t) getProc("getDisplayWidth", userData);
	getDisplayHeight = (getDisplayHeight_server_proc_t) getProc("getDisplayHeight", userData);
	getDisplayFPS = (getDisplayFPS_server_proc_t) getProc("getDisplayFPS", userData);
	getDisplayXDpi = (getDisplayXDpi_server_proc_t) getProc("getDisplayXDpi", userData);
	getDisplayYDpi = (getDisplayYDpi_server_proc_t) getProc("getDisplayYDpi", userData);
	postVirtualDisplay = (postVirtualDisplay_server_proc_t) getProc("postVirtualDisplay", userData);
	postAllVirtualDisplaysDone = (postAllVirtualDisplaysDone_server_proc_t) getProc("postAllVirtualDisplaysDone", userData);
	postBoForScreenRecord = (postBoForScreenRecord_server_proc_t) getProc("postBoForScreenRecord", userData);
	postCaptureScreenColorBuffer = (postCaptureScreenColorBuffer_server_proc_t) getProc("postCaptureScreenColorBuffer", userData);
	authenticateMagic = (authenticateMagic_server_proc_t) getProc("authenticateMagic", userData);
	updateSharingScreenDisplay = (updateSharingScreenDisplay_server_proc_t) getProc("updateSharingScreenDisplay", userData);
	return 0;
}

