source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/foreseecode/podspecs'

platform :ios, '10.0'
workspace 'ForeSeeSamples.xcworkspace'

def foresee_pods
    pod 'ForeSee-test', '5.2.0-RC17'
end

target "CustomInvitationSample" do
    project 'CustomInvitationSample/CustomInvitationSample.xcodeproj'
    pod 'SSSnackbar', '~> 0.1.2'
    pod 'SVProgressHUD', '~> 2.0.3'
    foresee_pods
end

target "BasicSample" do
    project 'BasicSample/BasicSample.xcodeproj'
    foresee_pods
end

target "BasicSwiftSample" do
    project 'BasicSwiftSample/BasicSwiftSample.xcodeproj'
    foresee_pods
end

target "ContactInvitationSample" do
    project 'ContactInvitationSample/ContactInvitationSample.xcodeproj'
    foresee_pods
end

target "InternationalizationSample" do
    project 'InternationalizationSample/InternationalizationSample.xcodeproj'
    foresee_pods
end

target "LocalNotificationSample" do
    project 'LocalNotificationSample/LocalNotificationSample.xcodeproj'
    foresee_pods
end

target "FeedbackSample" do
    project 'FeedbackSample/FeedbackSample.xcodeproj'
    foresee_pods
    # include the optional Feedback pod
    pod 'ForeSee-test/ForeSeeFeedback', '5.2.0-RC17'
end
