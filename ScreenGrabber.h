//
//  ScreenGrabber.h
//  files
//
//  Created by Scott Penberthy on 4/14/13.
//  Copyright (c) 2013 Scott Penberthy. All rights reserved.
//

#import <Quartz/Quartz.h>
#import <Foundation/Foundation.h>

@interface ScreenGrabber : NSObject
{
    BOOL grabbing;
    NSImage *grabbedImage;
    NSString *grabbedImageFilename;
}

@property (nonatomic, retain) NSImage *grabbedImage;
@property (nonatomic, retain) NSString *grabbedImageFilename;

- (NSString *) grab: (NSString *) path;

@end
