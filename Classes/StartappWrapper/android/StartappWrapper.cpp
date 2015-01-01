/*
 * StartappWrapper.cpp
 *
 *  Created on: 2014-11-19
 *      Author: alberthe
 */

#include "../StartappWrapper.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"

using namespace cocos2d;

static StartappWrapper * s_Instance = NULL;

StartappWrapper * StartappWrapper::getInstance(){
	if(s_Instance == NULL){
		s_Instance = new StartappWrapper();
	}

	return s_Instance;
}

void StartappWrapper::showInterstitial(){
	JniMethodInfo minfo;
	bool isHave = JniHelper::getStaticMethodInfo(minfo,
			"com/freeman/startappwrapper/StartappWrapper","showInterstitial","()V");
	if(!isHave){
			//CCLog("jni:openURL 函数不存在");
	}else{
		minfo.env->CallStaticVoidMethod(minfo.classID,minfo.methodID);
	}
}

void StartappWrapper::onBackPress(){
    JniMethodInfo minfo;
    bool isHave = JniHelper::getStaticMethodInfo(minfo,
                                                 "com/freeman/startappwrapper/StartappWrapper","onBackPressed","()V");
    if(!isHave){
        //CCLog("jni:openURL 函数不存在");
    }else{
        minfo.env->CallStaticVoidMethod(minfo.classID,minfo.methodID);
    }
}
