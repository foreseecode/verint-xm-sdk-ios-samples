platform :ios, '12.0'
workspace 'ForeSeeSamples.xcworkspace'
use_frameworks!

def foresee_pods
    pod 'ForeSee', '5.2.1'
end

target "CustomInvitationSample" do
    project 'CustomInvitationSample/CustomInvitationSample.xcodeproj'
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
    pod 'ForeSee/ForeSeeFeedback', '5.2.1'
end
