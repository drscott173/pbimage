//
//  main.m
//  pbimage
//
//  Created by Scott Penberthy on 1/17/14.
//  Copyright (c) 2014 Scott Penberthy. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "ScreenGrabber.h"

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        // insert code here...
        NSString *path = NULL, *arg = NULL;

        if (argc > 1) {
            path = [NSString stringWithFormat: @"%s", argv[1]];
            arg = [path lowercaseString];
            if ([arg hasPrefix: @"-h"] || [arg hasPrefix: @"--h"] ||
                [arg hasPrefix: @"-?"] || [arg hasPrefix: @"--?"]) {
                printf("\nUsage: pbimage <filename>\n\npbimage creates a PNG image from the clipboard image data.\n0 is returned on success, and the filename is pushed onto the clipboard.\nIf no filename is specified, a temporary file is used.\n\n1 is returned on failure.\n\n");
                return 0;
            }
        }
        
        ScreenGrabber *g = [[ScreenGrabber alloc] init];
        NSString *returnPath = [g grab: path];
        if (returnPath != NULL) {
            return 0;
        }
        else {
            printf("Unable to grab screen image.  Are you sure its on the clipboard?\n");
            return 1;
        }
    }
}

