#include <stdComs.h>
#include <lilOS.h>			// for the OSPtr.


// **************************************************************
// ***********************		listener		***********************
// **************************************************************


listener::listener(void) {  }

listener::~listener(void) {  }
	
void listener::handleCom(stdComs comID) {  }



// **************************************************************
// ***********************		stdCom		***********************
// **************************************************************


stdComBtn::stdComBtn(int xLoc,int yLoc,const char* path,stdComs iconType,listener* inListener,int pixles)
	:iconButton(xLoc,yLoc,path,pixles) { 
	
	ourListener = inListener;
	ourComID		= iconType;
}


stdComBtn::~stdComBtn(void) {  }

	
void stdComBtn::doAction(void) {

	OSPtr->beep();
	ourListener->handleCom(ourComID);
}


// Need a standard label icon? Here you go!
bmpObj* newStdLbl(int x,int y,iconSize inSize,stdLabels iconType) {

	bmpObj*	anBmpObjPtr;

	anBmpObjPtr = NULL;
	switch (iconType) {
		case warnLbl		:
			if (inSize==icon32) {
				anBmpObjPtr = new bmpObj(x,y,32,32,OSPtr->getStdIconPath(warn32));
			}
		break;
		case choiceLbl		:
			if (inSize==icon32) {
				anBmpObjPtr = new bmpObj(x,y,32,32,OSPtr->getStdIconPath(choice32));
			}
		break;
		case noteLbl		:
			if (inSize==icon32) {
				anBmpObjPtr = new bmpObj(x,y,32,32,OSPtr->getStdIconPath(note32));
			}
		break;
		case folderLbl		:
			if (inSize==icon16) {
				anBmpObjPtr = new bmpObj(x,y,16,16,OSPtr->getStdIconPath(folder16));
			}
		break;
		case folderRetLbl	:
			if (inSize==icon16) {
				anBmpObjPtr = new bmpObj(x,y,16,16,OSPtr->getStdIconPath(fldrRet16));
			}
		break;
		case docLbl			:
			if (inSize==icon16) {
				anBmpObjPtr = new bmpObj(x,y,16,16,OSPtr->getStdIconPath(doc16));
			}
		break;
		case SDCardLbl		:
			if (inSize==icon16) {
				anBmpObjPtr = new bmpObj(x,y,16,16,OSPtr->getStdIconPath(SDCard16));
			}
		break;
	}
	if (anBmpObjPtr) {
		if (inSize==icon32) {
			anBmpObjPtr->setMask(&(OSPtr->icon32Mask));
		}
	}
	return anBmpObjPtr;
}


// Need a standard button? Let us create one for you!
stdComBtn* newStdBtn(int x,int y,iconSize inSize,stdComs iconType,listener* inListener) {

	stdComBtn*	anIconPtr;

	anIconPtr = NULL;
	switch (iconType) {
		case cutCmd		:
			if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(cut32),iconType,inListener,32);
			}		
		break;
		case copyCmd	:
			if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(copy32),iconType,inListener,32);
			}		
		break;
		case closeCmd	:
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(x22),iconType,inListener,22);
			}		
		break;
		case pasteCmd :
			if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(paste32),iconType,inListener,32);
			}		
		break;
		case cancelCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(x22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(x32),iconType,inListener,32);
			}	
		break;
		case okCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(check22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(check32),iconType,inListener,32);
			}	
		break;
		case newFileCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(fNew22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(fNew32),iconType,inListener,32);
			}	
		break;
		case newFolderCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(FdrNew22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(FdrNew32),iconType,inListener,32);
			}	
		break;
		case newItemCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(cross22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(cross32),iconType,inListener,32);
			}	
		break;
		case openFileCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(fOpen22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(fOpen32),iconType,inListener,32);
			}	
		break;
		case saveFileCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(fSave22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(fSave32),iconType,inListener,32);
			}	
		break;
		case deleteItemCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(trashC22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(trashC32),iconType,inListener,32);
			}	
		break;
		case searchCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(search22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(search32),iconType,inListener,32);
			}	
		break;
		case sortCmd	:
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(sort22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(sort32),iconType,inListener,32);
			}	
		break;
		case editCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(edit22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(edit32),iconType,inListener,32);
			}	
		break;
		case readmeCmd :
			if (inSize==icon22) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(qMark22),iconType,inListener,22);
			}	else if (inSize==icon32) {
				anIconPtr = new stdComBtn(x,y,OSPtr->getStdIconPath(qMark32),iconType,inListener,32);
			}	
		break;
	}
	if (anIconPtr) {
		if  (inSize==icon22) {
			anIconPtr->setMask(&(OSPtr->icon22Mask));
		} else if (inSize==icon32) {
			anIconPtr->setMask(&(OSPtr->icon32Mask));
		}
	}
	return anIconPtr;
}
