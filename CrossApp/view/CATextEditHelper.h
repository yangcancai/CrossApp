//
//  CATextEditHelper.h
//  CrossApp
//
//  Created by Zhujian on 15-2-2.
//  Copyright (c) 2014 http://www.9miao.com All rights reserved.
//

#ifndef __CrossApp_CATextEditHelper__
#define __CrossApp_CATextEditHelper__

#include "CAView.h"
#include "CAScrollView.h"
#include "CAScale9ImageView.h"
#include "dispatcher/CAIMEDispatcher.h"
#include "control/CAButton.h"


#define CATextArrowViewWidth 30
#define CATextArrowViewHeight 62


NS_CC_BEGIN

typedef void (CAObject::*SEL_CATextEditBtnEvent)(int iButtonIndex);
#define CATextToolBar_selector(_SELECTOR) (SEL_CATextEditBtnEvent)(&_SELECTOR)


class CATextToolBar : public CAView
{
	friend class CALabel;
	friend class CATextField;
public:
	CATextToolBar();
	virtual ~CATextToolBar();

	static CATextToolBar *createWithText(const char* pszBtnText, ...);
	static void hideTextToolBar();

protected:
	void setTarget(CAObject* target, SEL_CATextEditBtnEvent selector);
	void showTextEditView(const CCPoint& point, CAView* pControlView);
	void hideTextEditView();

	void addButton(const std::string& btnText, CAColor4B col = ccc4(3, 100, 255, 255), CAImage* pNormalImage = NULL, CAImage* pHighlightedImage = NULL);
	void onClickButton(CAControl* btn, CCPoint point);
	bool ccTouchBegan(CATouch *pTouch, CAEvent *pEvent);

private:
	CAVector<CAButton*> m_vAllBtn;

	CAObject* m_pCATextTarget;
	SEL_CATextEditBtnEvent m_pCAEditBtnEvent;

	CAView* m_pControlView;
};

#define ZZSELECT_VIEW_SIZE 20

class CATextSelectView : public CAView
{
	friend class CATextField;
public:
	CATextSelectView();
	virtual ~CATextSelectView();
	
	static CATextSelectView *create();
	static void hideTextSelectView();

protected:
	virtual bool init();
	virtual bool ccTouchBegan(CATouch *pTouch, CAEvent *pEvent);
	virtual void ccTouchMoved(CATouch *pTouch, CAEvent *pEvent);
	virtual void ccTouchEnded(CATouch *pTouch, CAEvent *pEvent);
	void showTextSelView(const CCRect& rect, CAView* pControlView, bool showLeft = true, bool showRight = true);
	void hideTextSelView();

private:
	CAImageView* m_pDotViewL;
	CAImageView* m_pDotViewR;
	CAView* m_pCursorMarkL;
	CAView* m_pCursorMarkR;
	CAImageView* m_pTextMask;
	CAView* m_pControlView;
	int m_iSelViewTouchPos;
};


class CATextArrowView : public CAView
{
	friend class CATextField;
public:
	CATextArrowView();
	virtual ~CATextArrowView();

	static CATextArrowView *create();
	static void hideTextArrowView();

protected:
	virtual bool init();
	virtual bool ccTouchBegan(CATouch *pTouch, CAEvent *pEvent);
	virtual void ccTouchMoved(CATouch *pTouch, CAEvent *pEvent);
	virtual void ccTouchEnded(CATouch *pTouch, CAEvent *pEvent);
	void showTextArrView(const CCPoint& pt, CAView* pControlView);
	void hideTextArrView();
	void ccTouchTimer(float interval);

private:
	bool m_isBtnPress;
	CAImageView* m_pArrowView;
	CAView* m_pControlView;

};

NS_CC_END

#endif //__CrossApp_CATextEditHelper__