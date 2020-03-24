platform :ios, '13.0'
workspace 'ForeSeeSamples.xcworkspace'
use_frameworks!

FORESEE_VERSION = '5.3.5'

def foresee_pods(include_feedback=false)
    pod 'ForeSee', FORESEE_VERSION
    pod 'ForeSee/ForeSeeFeedback', FORESEE_VERSION if include_feedback
end

target "CustomInvitationSample" do
    project 'CustomInvitationSample/CustomInvitationSample.xcodeproj'
    foresee_pods
end

target "AdvancedSample" do
    project 'AdvancedSample/AdvancedSample.xcodeproj'
    foresee_pods true
end

target "BasicSample" do
    project 'BasicSample/BasicSample.xcodeproj'
    foresee_pods
end

target "AdobeExtensionSample" do
    project 'AdobeExtensionSample/AdobeExtensionSample.xcodeproj'
    pod 'ForeSeeAdobeExtension', '~> 1.0'
    pod 'ACPCore', '~> 2.0'
    pod 'ACPUserProfile', '~> 2.0'
end

target "SwiftSample" do
    project 'BasicSwiftSample/BasicSwiftSample.xcodeproj'
    foresee_pods
end

target "ContactInvitationSample" do
    project 'ContactInvitationSample/ContactInvitationSample.xcodeproj'
    foresee_pods
end

target "LocalNotificationSample" do
    project 'LocalNotificationSample/LocalNotificationSample.xcodeproj'
    foresee_pods
end

target "FeedbackSample" do
    project 'FeedbackSample/FeedbackSample.xcodeproj'
    foresee_pods true
end
