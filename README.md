## Projects
All projects can be found in: `ForeSeeSamples.xcworkspace`
## AdobeExtensionSample

### Prerequisites

To run this Sample, you need a [Adobe Experience Platform Launch](https://www.adobe.com/experience-platform/launch.html) account, and have set it up to use in mobile Apps.  

### Installing
1.  In the Adobe Launch dashboard, create a new Property for Mobile platform.
2.  Find and install the ForeSee SDK from the extension category. In the Configuration page, you can choose to enable `Debug Logging` and `Skip Pooling Check`<br/>
     ![Configuration](https://raw.githubusercontent.com/foreseecode/foresee-sdk-ios-samples/MOBILSDK-1608/AdobeExtensionSample/docresources/configuration.png)
3.  Create a Rule  
    Set the rule to trigger the ForeSee extension's Action: `ForeSee - Check Eligibility`. This will allow ForeSee SDK to check if the user is eligible for a survey. As below:<br/>
    ![Rule](https://raw.githubusercontent.com/foreseecode/foresee-sdk-ios-samples/MOBILSDK-1608/AdobeExtensionSample/docresources/rule.png)
4.  Create an Environment.
5.  In Publishing, create a Library.
6.  Add the Rule you created, and make sure the ForeSee extension is installed. Save and Build.
7.  Follow the development environment mobile install instructions.
8.  In file `FSAppDelegate.m`, replace the AppID in  `[ACPCore configureWithAppId:@"launch-your-appID"]` with your own app ID.

### Running the Sample

After launching the sample app, background / foreground the app three times to trigger a CXMeasure invite. You can also update the `foresee_configuration.json` to change the trigger criteria.

## AdvancedSample
This sample project demonstrates a more advanced implementation of the ForeSee trigger code in an empty iPhone app.

Features:

* A ForeSee measure survey triggered by a "significant event" count, which can be incremented using a button in the app. The user will 
become eligibile to receive and invitation once a configured threshold is met.
* A ForeSee Feedback survey 
* Localization of invites/survey. This app supports invite text overrides for Spanish, French, German, and Portuguese and can show surveys in English, French, and Spanish. 
Change your device's language setting to view invites/surveys in another language.



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


## FeedbackSample
This sample project demonstrates a Swift implementation of the ForeSee Feedback Survey code and configuration. 


## LocalNotificationSample
This sample project demonstrates a local notification invite. Accept the invite and then close the application. 
You will receive a local notification linking the survey.


