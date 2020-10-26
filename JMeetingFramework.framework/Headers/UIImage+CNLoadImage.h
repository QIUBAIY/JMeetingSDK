//
//  UIImage+CNLoadImage.h
//  ConferenceSDK
//
//  Created by Setoge on 2020/3/29.
//  Copyright © 2020 redcdn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (CNLoadImage)
+ (UIImage *)loadImageWithName:(NSString *)imageName;
+ (UIImage *)imageInBundleWithNamed:(NSString *)name;
@end

NS_ASSUME_NONNULL_END
