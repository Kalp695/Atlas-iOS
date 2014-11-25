//
//  LYRUIMessageInputToolbar.h
//  Pods
//
//  Created by Kevin Coleman on 9/18/14.
//
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import "LYRUIMessageComposeTextView.h"

/**
 @abstract The `LYRUIMessageInputToolbar` provides a light weight and customizable class
 that is similar to the MessageInputToolbar in iMessage. 
 @discussion The class displays two customiazable UIButtons seperated by a message input textView. 
 The class automatically resizes itself in response to user or system input content. The view also 
 caches any content provided and exposes that content back to a consuming object via the 
 messageContentParts property.
 */
@class LYRUIMessageInputToolbar;

//---------------------------------
// Message Input Toolbar Delegate
//---------------------------------

/**
 @abstract The `LYRUIMessageInputToolbarDelegate` notifies its reciever when buttons have been 
 tapped.
 */
@protocol LYRUIMessageInputToolbarDelegate <NSObject>

/**
 @abstract Notifies the reciever that the right accessory button was tapped
 */
- (void)messageInputToolbar:(LYRUIMessageInputToolbar *)messageInputToolbar didTapRightAccessoryButton:(UIButton *)rightAccessoryButton;

/**
 @abstract Notifies the reciever that the left accessory button was tapped
 */
- (void)messageInputToolbar:(LYRUIMessageInputToolbar *)messageInputToolbar didTapLeftAccessoryButton:(UIButton *)leftAccessoryButton;

@optional

/**
 @abstract Notifies the reciever that typing has begun.
 */
- (void)messageInputToolbarDidBeginTyping:(LYRUIMessageInputToolbar *)messageInputToolbar;

/**
 @abstract Notifies the reciever that typing has ended.
 */
- (void)messageInputToolbarDidEndTyping:(LYRUIMessageInputToolbar *)messageInputToolbar;

@end

@interface LYRUIMessageInputToolbar : UIToolbar

//------------------------------
// Content Display Methods
//------------------------------

/**
 @abstract Displays an image in the textInputView.
 @discussion The view will automatically resize the image and itself to comfortably
 fit the image content. The image will also be cached and is accessible via the messageContentParts
 property.
 */
- (void)insertImage:(UIImage *)image;

/**
 @abstract Displays an image representing a location in the textInputView.
 @discussion The view will automatically resize the image representing the location and itself to 
 comfortably fit the image content. The location object will also be cached and is accessible 
 via the messageContentParts property.
 */
- (void)insertLocation:(CLLocation *)location;

//-----------------------------
// UI Customization
//-----------------------------

/**
 @abstract The left accessory button for the view. 
 @discussion By default, the button displays a camera icon
 */
@property (nonatomic) UIButton *leftAccessoryButton;

/**
 @abstract The right accessory button for the view.
 @discussion By default, the button displays the text "SEND"
 */
@property (nonatomic) UIButton *rightAccessoryButton;

/**
 @abstract A Boolean value indicating whether the receiver can enable its send button.
 @discussion By default, the button can be enabled.
 */
@property (nonatomic) BOOL canEnableSendButton;

/**
 @abstract An automatically resizing message composisiton field
 */
@property (nonatomic) LYRUIMessageComposeTextView *textInputView;

/**
 @abstract The delegate object for the view
 */
@property (nonatomic, weak) id<LYRUIMessageInputToolbarDelegate>inputToolBarDelegate;

/**
 @abstract The maximum number of lines of next to be displayd
 @default 6
 @discussion The text view will stop growing once 6 lines are displayed. It
 will scroll its text view to keep the latest content visible
 */
@property (nonatomic) NSUInteger maxNumberOfLines;

/**
 @abstract An array of all content parts displayed in the view. 
 @discussion Any existing objects will be removed when the right accessory button is tapped
 */
@property (nonatomic, readonly) NSArray *messageParts;

@end
