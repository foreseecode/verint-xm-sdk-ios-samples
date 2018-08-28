# Sample Projects

These sample projects demonstrate typical usage of the ForeSee SDK.

## Installation

All sample projects use [Cocoapods](http://cocoapods.org/). The Pods and workspace folders are
included, so it isn't strictly necessary to manually install anything. 

### Known issues / Troubleshooting

Some users have reported the following error on first run ([#12](https://github.com/foreseecode/foresee-sdk-ios-samples/issues/12)):

    dyld: Library not loaded: @rpath/ForeSee.framework/ForeSee
     Referenced from: /Users/uiwehb/Library/Developer/CoreSimulator/Devices/8FAE80C7-CE04-4F4A-BD4C-95EAB508C733/data/Containers/Bundle/Application/FBC926AF-540F-4AB1-8E2D-7FEEA3FC77E7/BasicSample.app/BasicSample
    Reason: image not found

This is fixed by re-installing pods from scratch with the following commands:

    $ sudo rm -r Pods/
    $ pod install

## Projects

All projects can be found in:

`ForeSeeSamples.xcworkspace`

## BasicSample
This sample project demonstrates a basic implementation of the ForeSee trigger code in an empty iPhone app.
It uses the provided FSInviteView to show a modal dialog to the user inviting them to take a survey when
they have met the configured threshold.

## BasicSwiftSample
This sample project demonstrates a basic Swift implementation of the ForeSee trigger code. It uses a bridging header to include the SDK.

## ContactInvitationSample
This example shows how to provide a user's contact information to the SDK for use in a CONTACT mode survey.

## CustomInvitationSample
This example demonstrates the use of a custom invite handler.

## InternationalizationSample
This sample project demonstrates how you can customize the default Invite View (FSInviteView) with text of your
choosing.  It also demonstrates how you can localize the invitation text using standard localization techniques
for iOS.  The demo app supports English, French, and Spanish.  Simply change the language setting of the test device
to see the invite in another language.

All strings used by the FSInviteView class are defined in the Localizable.strings file.

## LocalNotificationSample
This sample project demonstrates a local notification invite. Accept the invite and then close the application. 
You will receive a local notification linking the survey.

## ReplaySample
This sample project demonstrates cxReplay.

