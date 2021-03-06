//
//  RDImageViewerController.h
//
//  Created by Akira Matsuda on 2014/03/20.
//  Copyright (c) 2014年 Akira Matsuda. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RDPagingView.h"
#import "RDImageScrollView.h"

@class RDImageViewerController;
@protocol RDImageViewerControllerDelegate <NSObject>
@optional
- (void)imageViewerController:(RDImageViewerController *)viewController willChangeIndexTo:(NSInteger)index;

@end

@interface RDImageViewerController : UIViewController <RDPagingViewDelegate, UIScrollViewDelegate>

extern NSString *const RDImageViewerControllerReuseIdentifierImage;

@property (nonatomic, assign) id<RDImageViewerControllerDelegate>delegate;
@property (nonatomic) NSUInteger preloadCount;
@property (nonatomic, assign) NSInteger pageIndex;
@property (nonatomic, assign) BOOL pagingEnabled;
@property (nonatomic, assign) BOOL loadAsync;
@property (nonatomic, assign) BOOL showSlider;
@property (nonatomic, assign) BOOL showPageNumberHud;
@property (nonatomic, assign) RDImageScrollViewResizeMode landscapeMode;
@property (nonatomic, assign) CGFloat maximumZoomScale;
@property (nonatomic, copy) UIColor *pageSliderMaximumTrackTintColor;
@property (nonatomic, copy) UIColor *pageSliderMinimumTrackTintColor;
@property (nonatomic, copy) UIImage *(^imageHandler)(NSInteger pageIndex);
@property (nonatomic, copy) UIView *(^viewHandler)(NSInteger pageIndex, UIView *reusedView);
@property (nonatomic, copy) NSString *(^reuseIdentifierHandler)(NSInteger pageIndex);

- (instancetype)initWithNumberOfPages:(NSInteger)num direction:(RDPagingViewForwardDirection)direction;
- (instancetype)initWithImageHandler:(UIImage *(^)(NSInteger pageIndex))imageHandler numberOfImages:(NSInteger)pageCount direction:(RDPagingViewForwardDirection)direction;
- (instancetype)initWithViewHandler:(UIView *(^)(NSInteger pageIndex, UIView *reusedView))viewHandler reuseIdentifier:(NSString *(^)(NSInteger pageIndex))reuseIdentifierHandler numberOfImages:(NSInteger)pageCount direction:(RDPagingViewForwardDirection)direction;

@end
