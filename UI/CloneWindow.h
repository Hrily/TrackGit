/**
 * @file CloneWindow.h
 * @brief Header file of Clone window.
 * 
 * @author Hrishikesh Hiraskar <hrishihiraskar@gmail.com>
 */

#ifndef _CLONE_WINDOW_H_
#define _CLONE_WINDOW_H_

#include "../ThirdParty/PathBox.h"
#include "TrackGitWindow.h"
#include "../GitCommand/Clone.h"

#include <git2.h>
#include <pthread.h>

#include <InterfaceKit.h>

enum {
	kDoClone,
	kCancel
};

class CloneProgressWindow;

class CloneWindow : public TrackGitWindow {
	/**
	 * The progress window.
	 */
	CloneProgressWindow* 	fProgressWindow;
	/**
	 * The text control for url.
	 */
	BTextControl* 			fURL;
	/**
	 * The text control for path.
	 */
	PathBox* 				fPathBox;
	/**
	 * The clone command pointer.
	 * Used to initiate cloning process.
	 */
	Clone* 					fClone;
	/**
	 * The thread Id of clone thread.
	 */
	pthread_t 				fThreadId;
	public:
							CloneWindow(BString, BString, Clone*);
	void					SetProgressText(BString);
	virtual void			MessageReceived(BMessage*);
};

class CloneProgressWindow : public BWindow
{
	/**
	 * The Clone Window pointer.
	 * Used to sent cancel BMessage.
	 */
	CloneWindow*		fCloneWindow;
	/**
	 * The text view to show progress text.
	 */
	BTextView*			fTextView;
	public:
						CloneProgressWindow(CloneWindow*);
	void				SetText(const char*);
	virtual void		MessageReceived(BMessage*);
};

#endif
