//
// MMTApi.h
// Maxymiser Mobile Testing iOS SDK
//
// Copyright(c) 2005-2014 Maxymiser Ltd, All Rights Reserved.

#import <Foundation/Foundation.h>

#import "MMTExperiences.h"

@protocol MMTApi <NSObject>

/// Sets the maximum time which can be spent making a request to our servers.
/// Default is 3 seconds.
/// When the time is exceeded, the attempt to fetch experiences will cease and the previous user experiences will be selected.
///
/// @param timeout Timeout to use.
///
- (void)setRequestTimeOut:(NSTimeInterval)timeout;

/// Specifies whether new experiences can be fetched only when user is connected to a Wi-Fi network. By default any available network will be used.
///
/// @param wifiOnly YES to use only Wi-Fi network, NO to use any available network.
///
- (void)setWiFiOnly:(BOOL)wifiOnly;

/// Specifies whether Sandbox configuration should be used. By default Production configuration will be used.
///
/// @param sandbox YES to use Sandbox configuration, NO to use Production configuration.
///
- (void)useSandbox:(BOOL)sandbox;

/// Fetches new experiences from Maxymiser platform for a default Page named ‘Generations’.
/// Fetching will be performed on a background thread.
///
/// @param handler A block that will be invoked once experiences are fetched.
///
- (void)fetchExperiences:(void (^)())handler;

/// Fetches new experiences from Maxymiser platform for a specified Page.
/// Fetching will be performed on a background thread.
///
/// @param handler A block that will be invoked once experiences are fetched.
/// @param page A Page for which you want to fetch experiences.
///
- (void)fetchExperiences:(void (^)())handler forPage:(NSString *)page;

/// Returns fetched experiences that should be used for content transformations.
///
/// @return Experiences previously fetched from Maxymiser platform. nil if experiences were not fetched.
///
- (id <MMTExperiences>)getExperiences;

/// Tracks a user action for a default Page named ‘Actions’.
///
/// @param name Name for the action which should exist in the site configuration in the Maxymiser UI.
/// @param value Integer value of the action. This can be used for the tracking of various parameters such as amount and sum.
/// @param attr The action attribute. This can be used for the tracking of various additional information related with the action.
///
- (void)trackAction:(NSString *)name value:(NSInteger)value attribute:(NSString *)attr;

/// Tracks a user action for a specified Page.
///
/// @param name Name for the action which should exist in the site configuration in the Maxymiser UI.
/// @param value Integer value of the action. This can be used for the tracking of various parameters such as amount and sum.
/// @param attr The action attribute. This can be used for the tracking of various additional information related with the action.
/// @param page The Page for which you want to track the action.
///
- (void)trackAction:(NSString *)name value:(NSInteger)value attribute:(NSString *)attr forPage:(NSString *)page;

/// Tracks a special type of action for confirmation that a user has been served the content.
///
/// @param campaign Campaign name which content was served.
///
- (void)trackContentSeen:(NSString *)campaign;

@end