/*
 * StartappWrapper.h
 *
 *  Created on: 2014-11-19
 *      Author: alberthe
 */

#ifndef STARTAPPWRAPPER_H_
#define STARTAPPWRAPPER_H_

class StartappWrapper {
public:

    static StartappWrapper * getInstance();

    // show interstitial ad
    void showInterstitial();
    
    // show back press ad
    void onBackPress();
};

#endif /* STARTAPPWRAPPER_H_ */
