//
//  ScreenGrabber.m
//  files
//
//  Created by Scott Penberthy on 4/14/13.
//  Copyright (c) 2013 Scott Penberthy. All rights reserved.
//

#import "ScreenGrabber.h"
#import "Defs.h"
#import <Carbon/Carbon.h>

@implementation ScreenGrabber
@synthesize grabbedImage, grabbedImageFilename;

- (NSString *) pathForImage: (NSString *) imageName
{
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSString *folder = [NSTemporaryDirectory() stringByAppendingPathComponent: kScreenshotFolder];
    folder = [folder stringByExpandingTildeInPath];
    NSString *fileName = [NSString stringWithFormat:@"%@.png", imageName];
    
    if ([fileManager fileExistsAtPath: folder] == NO)
    {
        NSError *error=nil;
        [fileManager createDirectoryAtPath: folder
               withIntermediateDirectories: YES
                                attributes:nil
                                     error: &error];
        if (error) {
            DDLogError(@"Unable to create local directory for screenshots:\n%@",
                  [error localizedDescription]);
        }
    }
    
    return [folder stringByAppendingPathComponent: fileName];
}

//saving an image
- (NSData *) PNGRepresentationOfImage:(NSImage *) image {
    // Create a bitmap representation from the current image
    
    [image lockFocus];
    NSBitmapImageRep *bitmapRep = [[NSBitmapImageRep alloc]
                                   initWithFocusedViewRect:NSMakeRect(0, 0, image.size.width, image.size.height)];
    [image unlockFocus];
    
    return [bitmapRep representationUsingType:NSPNGFileType properties:Nil];
}

- (void)saveImage:(NSImage*)image withName: (NSString*)imageName {
    NSData *imageData = [self PNGRepresentationOfImage: image];
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSString *fullPath = [self pathForImage: imageName];
    
    [fileManager createFileAtPath:fullPath contents:imageData attributes:nil];
    DDLogVerbose(@"image saved");
}

- (void)saveImage:(NSImage*)image withPath: (NSString*)fullPath {
    NSData *imageData = [self PNGRepresentationOfImage: image];
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    [fileManager createFileAtPath:fullPath contents:imageData attributes:nil];
    DDLogVerbose(@"image saved");
}


- (NSString *) screenShotFilename
{
    // Get current datetime
    NSDate *currentDateTime = [NSDate date];
    
    // Instantiate a NSDateFormatter
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    
    // Set the dateFormatter format
    [dateFormatter setDateFormat:@"yyyy-MM-dd K.mm.ss a"];
    
    // Get the date time in NSString
    NSString *dateInString = [NSString stringWithFormat:
                              @"Screen shot at %@",[dateFormatter stringFromDate:currentDateTime]];
    
    return dateInString;
}

// return our pathname
- (NSString *) grab: (NSString *) path
{

    if (path == nil) {
        path = [self pathForImage: [self screenShotFilename]];
    }
    
    NSPasteboard *pb = [NSPasteboard generalPasteboard];

    // store image
    NSData *archived_data = [pb dataForType:NSTIFFPboardType];
    if (archived_data) {
        self.grabbedImage = [[NSImage alloc] initWithData: archived_data];
        self.grabbedImageFilename = path;
        [self saveImage: self.grabbedImage withPath: self.grabbedImageFilename];
        grabbing = NO;
        [pb clearContents];
        
        NSData *pathData = [path dataUsingEncoding:NSUTF8StringEncoding];
        
        [pb setData: pathData forType: NSStringPboardType];
        return path;
    }
    return NULL;
}

@end
