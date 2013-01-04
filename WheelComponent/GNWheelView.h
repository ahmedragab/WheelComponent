//
//  GNWheelView.h
//  WheelComponent
//
//  Copyright (c) 2012 Ahmed Ragab
//
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>

@protocol GNWheelViewDelegate;

@interface GNWheelView : UIView <UIGestureRecognizerDelegate>{
    
    NSMutableArray *_views;
    NSMutableArray *_viewsAngles;
    NSMutableArray *_originalPositionedViews;
    unsigned int viewsNum;
    
    UIView *idleView;
    BOOL idleViewAnimated;
    
    BOOL toDescelerate;
    
    BOOL toRearrange;
}

@property (nonatomic,assign) NSObject<GNWheelViewDelegate> *delegate;
@property (nonatomic,readwrite) int idleDuration;


- (void)reloadData;

@end

@protocol GNWheelViewDelegate

@required

- (unsigned int)numberOfRowsOfWheelView:(GNWheelView *)wheelView;
- (UIView *)wheelView:(GNWheelView *)wheelView viewForRowAtIndex:(unsigned int)index;
- (float)rowWidthInWheelView:(GNWheelView *)wheelView;
- (float)rowHeightInWheelView:(GNWheelView *)wheelView;

@optional

- (void)wheelView:(GNWheelView *)wheelView didSelectedRowAtIndex:(unsigned int)index;
- (BOOL)wheelView:(GNWheelView *)wheelView shouldEnterIdleStateForRowAtIndex:(unsigned int)index animated:(BOOL*)animated;
- (UIView *)wheelView:(GNWheelView *)wheelView idleStateViewForRowAtIndex:(unsigned int)index;
- (void)wheelView:(GNWheelView *)wheelView didStartIdleStateForRowAtIndex:(unsigned int)index;


@end