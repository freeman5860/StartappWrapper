package com.freeman.startappwrapper;

import java.lang.ref.WeakReference;

import android.app.Activity;

import com.startapp.android.publish.StartAppAd;
import com.startapp.android.publish.StartAppSDK;

public class StartappWrapper {
	
	private static WeakReference<Activity> mActivity;
	
	private static final String DEVELOP_ID = "104544865";
	private static final String APP_ID = "212832670";
	
	private static StartAppAd startAppAd = null;
	
	public static void onCreate(Activity act){
		mActivity = new WeakReference<Activity>(act);
		StartAppSDK.init(mActivity.get(), DEVELOP_ID, APP_ID, false);
		
		startAppAd = new StartAppAd(mActivity.get());
        startAppAd.loadAd();
	}
	
	public static void onResume(){
        mActivity.get().runOnUiThread(new Runnable() {
            
            @Override
            public void run() {
                if(startAppAd != null){
                    startAppAd.onResume();
                }
            }
        });
	}
	
	public static void onPause(){
        mActivity.get().runOnUiThread(new Runnable() {
            
            @Override
            public void run() {
                if(startAppAd != null){
                    startAppAd.onPause();
                }
            }
        });
		
	}
	
	public static void onBackPressed() {
        mActivity.get().runOnUiThread(new Runnable() {
            
            @Override
            public void run() {
                if(startAppAd != null){
                    startAppAd.onBackPressed();
                }
            }
        });
		
	}
	
	public static void showInterstitial(){
        mActivity.get().runOnUiThread(new Runnable() {
            
            @Override
            public void run() {
                if(startAppAd != null){
                    System.out.println("load ad!!!!");
                    startAppAd.showAd();
                    startAppAd.loadAd();
                }
            }
        });
		
	}

	public static void showSplashAd(){
		
	}
}
