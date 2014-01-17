//
//  Defs.h
//  files
//
//  Created by Scott Penberthy on 3/23/13.
//  Copyright (c) 2013 Scott Penberthy. All rights reserved.
//

#import "DDLog.h"

// Log levels: off, error, warn, info, verbose
static const int ddLogLevel = LOG_LEVEL_ERROR;

#define USE_GOOGLE
#define APP_STORE

// In-App Purchases (IAP)

#define IAP_SECRET      @"53c74508727d443c833f4ba7b3bdb0d3"
#define IAP_BANDWIDTH   @"files.bandwidth"
#define IAP_ONETIME     @"files.onetime"
#define IAP_PW          @"files.password"
#define IAP_RECEIPT     @"files.receipt"
#define IAP_MONTH       @"files.subscribe"

#define DEBUG 1
//#define DEBUG_API 1

#ifdef DEBUG_API
#define TEST_FAIL (rand()%10000 > 9000)
#endif

#ifndef DEBUG_API
#define TEST_FAIL NO
#endif

#ifndef files_Defs_h
#define files_Defs_h


#define kFacebookApplicationID @"129420773820171"
#define iTunesSharedSecret @"53c74508727d443c833f4ba7b3bdb0d3"
#define kImageMaxDimension 2000

// Services
#define kFilesService  @"com.nhp.files"
#define kVersionKey    @"com.nhp.files.installed.v1"
#define kVersionString  @"v1.0"

// Authorization shortcut
#define kSessionToken [(AppDelegate *) [[NSApplication sharedApplication] delegate] sessionToken]

// Files
// was ~/Library/Containers/com.nhp.files/Data/Library/Application Support/
#define kThumbFolder @"files/thumbs/"
#define kImageFolder @"files/images/"
#define kPartFolder @"files/parts/"
#define kZipFolder @"files/zip/"
#define kPtreeFile @"files/contacts.dat"
#define kScreenshotFolder @"files/screenshots/"
#define kTestPath @"/Users/spenberthy001/Downloads/ktr_cell.mp4"

// Local executables
#define kFFProbePath @"/Users/spenberthy001/Downloads/ffprobe"
#define kFFMpegPath @"/Users/spenberthy001/Downloads/ffmpeg"

// URL templates
#define kURLS3Bucket @"http://%@.s3.amazonaws.com/"
#define kURLFacebookPic @"http://graph.facebook.com/%@/picture?type=square"

#ifndef USE_GOOGLE
// API endpoints
#define kAPIHostName        @"localhost:8080"
#define kURLClone           @"http://localhost:8080/clone"
#define kURLFindObject      @"http://localhost:8080/find"
#define kURLLogin           @"http://localhost:8080/login"
#define kURLSignup          @"http://localhost:8080/signup"
#define kURLLogout          @"http://localhost:8080/logout"
#define kURLGetAccountInfo  @"http://localhost:8080/account"
#define kURLEmailInfo       @"http://localhost:8080/emailInfo"
#define kURLLostPassword    @"http://localhost:8080/forgot"
#define kURLBuy             @"http://localhost:8080/buy"
#define kURLCloseAccount    @"http://localhost:8080/close_account"
#define kURLGetUploadParms  @"http://localhost:8080/sign_s3_post"
#define kURLSendMail        @"http://localhost:8080/transfer"
#define kURLChangePassword  @"http://localhost:8080/set_password"
#define kStartUploadURL     @"http://localhost:8080/mstart"
#define kAddPartURL         @"http://localhost:8080/mpart"
#define kCancelURL          @"http://localhost:8080/mcancel"
#define kCompleteURL        @"http://localhost:8080/mdone"
#define kURLAccountInfo     @"http://localhost:8080/s/account.html"
#define kURLStartup         @"http://localhost:8080/s/login.html"
#define kURLSendDialog      @"http://localhost:8080/s/send.new.html"
#define kURLProgress        @"http://localhost:8080/s/progress.html"
#define kURLZip             @"http://localhost:8080/s/zip.html"
#define kURLBugReport       @"http://localhost:8080/bug"
#define kURLPingLogin       @"http://localhost:8080/ok?a=startup"
#define kURLPingTemplate    @"http://localhost:8080/ok?a=%@"
#define kURLFeedbackForm    @"http://localhost:8080/s/feedback.html"
#endif

#ifdef USE_GOOGLE
#define kAPIHostName        @"api.instntly.com"
#define kURLBuyBandwidth    @"http://api.instntly.com/addbw"
#define kURLClone           @"http://api.instntly.com/clone"
#define kURLFindObject      @"http://api.instntly.com/find"
#define kURLLogin           @"http://api.instntly.com/login"
#define kURLSignup          @"http://api.instntly.com/signup"
#define kURLLogout          @"http://api.instntly.com/logout"
#define kURLGetAccountInfo  @"http://api.instntly.com/account"
#define kURLEmailInfo       @"http://api.instntly.com/emailInfo"
#define kURLLostPassword    @"http://api.instntly.com/forgot"
#define kURLBuy             @"http://api.instntly.com/buy"
#define kURLCloseAccount    @"http://api.instntly.com/close_account"
#define kURLGetUploadParms  @"http://api.instntly.com/sign_s3_post"
#define kURLSendMail        @"http://api.instntly.com/transfer"
#define kURLChangePassword  @"http://api.instntly.com/set_password"
#define kURLSendFeedback    @"http://api.instntly.com/feedback"
#define kStartUploadURL     @"http://api.instntly.com/mstart"
#define kAddPartURL         @"http://api.instntly.com/mpart"
#define kCancelURL          @"http://api.instntly.com/mcancel"
#define kCompleteURL        @"http://api.instntly.com/mdone"
#define kURLAccountInfo     @"http://api.instntly.com/s/account.html"
#define kURLFeedbackForm    @"http://api.instntly.com/s/feedback.html"
#define kURLStartup         @"http://api.instntly.com/s/login.html"
#define kURLSendDialog      @"http://api.instntly.com/s/send.new.html"
#define kURLProgress        @"http://api.instntly.com/s/progress.html"
#define kURLZip             @"http://api.instntly.com/s/zip.html"
#define kURLBugReport       @"http://api.instntly.com/bug"
#define kURLPingLogin       @"http://api.instntly.com/ok?a=startup"
#define kURLPingTemplate    @"http://api.instntly.com/ok?a=%@"
#endif


#define kEventGrab @"grab"
#define kSendWindowName @"SendWindow"
#define kSendProgessWindow @"SendProgress"

// Keys
#define kKeyFilePath        @"file_path"
#define kKeyFileParms       @"file_parms"
#define kKeyThumbParms      @"thumb_parms"
#define kKeyThumbPath       @"thumb_path"
#define kKeyFormInfo        @"form_info"
#define kKeyMailTo          @"to"
#define kKeyMailFrom        @"from"
#define kKeyMailAuthor      @"name"
#define kKeyMailFacebookID  @"fbid"
#define kKeyMailSubject     @"subject"
#define kKeyMailThumbnail   @"thumb"
#define kKeyMailFile        @"file"
#define kKeyMailBody        @"body"
#define kKeyS3UploadForm    @"form_info"
#define kKeyMailIsVideo     @"video"
#define kKeyS3Bucket        @"bucket"
#define kKeyCount           @"count"
#define kKeyFilename        @"pathname"
#define kKeyFileHandle      @"handle"
#define kKeyFileLength      @"length"
#define kKeyStatus          @"status"
#define kKeyMessage         @"message"
#define kKeyTitle           @"title"
#define kKeyIcon            @"icon"
#define kKeyPoster          @"poster"

// S3 keys
#define kKeyS3Object        @"key"
#define kKeyS3Filename      @"s3name"
#define kKeyS3Mime          @"s3type"
#define kKeyTargetObject    @"s3obj"
#define kKeyTargetID        @"s3id"
#define kKeyS3Size          @"s3size"
#define kKeyS3Part          @"s3part"
#define kKeyS3IsAttachment  @"s3attach"

// FFProbe keys
#define kKeyFFProbeStreams  @"streams"
#define kKeyFFProbeWidth    @"width"
#define kKeyFFProbeHeight   @"height"
#define kKeyFFProbeDuration @"duration"
#define kKeyFFProbeBytes    @"length"

// FilesAPI keys
#define kKeyFilesObject     @"object"
#define kKeyFilesID         @"id"
#define kKeyFilesURL        @"url"
#define kKeyFilesPostForm   @"form"


// Growl
#define kGrowlStatus @"status"

// Facebook

#define kFBResult           @"result"
#define kFBRequest          @"request"
#define kFBError            @"error"
#define kFBEmail            @"email"
#define kFBMe               @"me"
#define kFBID               @"id"
#define kFBUsername         @"username"
#define kFBNormal           @"normal"
#define kFBRequestType      @"type"
#define kFBEmailAddressTemplate  @"%@@facebook.com"
#define kFBMyFriends        @"me/friends"
#define kFBValid            @"valid"
#define kFBFieldList @"id,name,first_name,middle_name,last_name,email,location,gender,username,birthday,relationship_status,website"
#define kFBFields           @"fields"
#define kFBData             @"data"
#define kFBPersonalName     @"name"

// Defaults
#define kFBFriendCount      @"com.nhp.files.facebookTotal"
#define kLoginEmail         @"com.nhp.files.login"
#define kLoginPassword      @"com.nhp.files.password"
#define kAuthToken          @"com.nhp.files.session"
#define kKeySmartSize       @"com.nhp.files.smartSize"


// Error codes
#define kErrorInnerMultipartFailed          @"1001"
#define kErrorLastMultipartFailed           @"1002"
#define kErrorEmptyFile                     @"5000"
#define kErrorPartUploadFailed              @"1004"
#define kErrorMultipartUnavailable          @"1000"

// UI Strings
#define kUIPleaseTryAgain       @"Please try again; we lost the internet connection."
#define kUISendFailed           @"Send Failed"
#define kUISendComplete         @"Send Complete"
#define kUIFilesSent            @"Your files have been sent."
#define kUIUploadTitle          @"Upload"
#define kUIUploadingNFiles      @"Uploading %d files"
#define kUIUploadScreenshot     @"Uploading screenshot"
#define kUISendingFile          @"Sending %@"
#define kUIReadingFile          @"Reading %@"
#define kUIAnalyzeFile          @"Analyzing %@"
#define kUIAddingFile           @"Adding %@"
#define kUIResizingFile         @"Resizing %@"
#define kUIConvertingFile       @"Converting %@"
#define kUITransmitTitle        @"Transmitting files"

#define kUIPartStuck            @"Part %d got stuck :-("
#define kUIPartSent             @"Part %d on its way."
#define kUIPartsDone            @"All parts uploaded!"
#define kUIUploadingPart        @"%@ (part %d)"
#define kUIPostComplete         @"Done. %@"
#define kUIPostFailed           @"Failed!  %@"

#define kUISendAFileTitle       @"Send a file"
#define kUISendFilesTitle       @"Sending %d files"
#define kUIPreparingChunk       @"Preparing 5MB"
#define kUIEmptyFile            @"We've encountered an empty file!  Nothing sent."
#define kUIMenuHover            @"Click me to send a file to a friend"
#define kUISendingPart          @"Sending %dMB"

#define kUIInnerMultipartPostFailed  @"I'm sorry a part didn't upload correctly.\n%@\nPlease try again."
#define kUIMultipartPostFailed  @"I'm sorry the last part didn't upload correctly.\n%@\nPlease try again."
#define kUIPartUploadFailed      @"The servers aren't letting us send files.\nMaybe its time to upgrade your plan!"
#define kUIMultipartUnavailable  @"Unable to start - internet not available."

// Images
#define kImageMenubar           @"menu_bunny.png"
#define kImageMenubarHover      @"menu_bunny_over.png"
#define kImageGrowlIcon         @"jatMotor_48x48.png"
#define kImageSendBackground    @"paper.png"

// Fonts
#define kSendWindowFont         @"Lucida Grande"
#define kSendWindowFontSize     13

// Regex
#define kRegexEmail             @"^[A-Z0-9._%+-]+@[A-Z0-9.-]+.[A-Z]{2,4}$"

// Timeout
#define kTimeoutInterval        6


#endif
