# Private repo for internal testing use only
#source 'https://github.com/CocoaPods/Specs.git'
#source 'https://github.com/foreseecode/podspecs'

platform :ios, '12.0'
workspace 'ForeSeeSamples.xcworkspace'

def foresee_pods
    pod 'ForeSee', '5.2.0-alpha'
end

target "CustomInvitationSample" do
    project 'CustomInvitationSample/CustomInvitationSample.xcodeproj'
    pod 'SSSnackbar', '~> 0.1.2'
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
    use_frameworks!
    project 'FeedbackSample/FeedbackSample.xcodeproj'
    foresee_pods
    # include the optional Feedback pod
    pod 'ForeSee/ForeSeeFeedback', '5.2.0-alpha'
end
