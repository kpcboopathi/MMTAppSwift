//
// MMTApp.h
// Maxymiser Mobile Testing iOS SDK
//
// Copyright(c) 2005-2014 Maxymiser Ltd, All Rights Reserved.

#import <Foundation/Foundation.h>

#import "MMTApi.h"
#import "MMTLogger.h"
#import "UIView+MMTApp.h"

/// Sets the maximum time which can be spent making a request to our servers.
/// Default is 3 seconds.
/// When the time is exceeded, the attempt to fetch experiences will cease and the previous user experiences will be selected.
/// Values @0 - @50. @0 for infinite timeout.
extern NSString *const MMTAppOptionTimeout;

/// Specifies whether new experiences can be fetched only when user is connected to a Wi-Fi network.
/// By default any available network will be used.
/// Values @YES/@NO
extern NSString *const MMTAppOptionWiFiOnly;

/// Specifies whether Sandbox configuration should be used.
/// By default Production configuration will be used.
/// Values @YES/@NO
extern NSString *const MMTAppOptionUseSandbox;

/// A Page for which you want to track the action.
/// By default actions will be tracked for @"Actions" page.
extern NSString *const MMTAppOptionActionsPage;

/// A Page name which will be used to fetch experiences.
/// By default experiences will be fetched from @"Generations" page.
extern NSString *const MMTAppOptionGenerationsPage;

@interface MMTApp : NSObject

/// Returns default API.
///
/// @return Returns API object set explicitly with +setDefaultApi: or first API object created with +apiForSite:, otherwise return nil.
///
+ (id <MMTApi>)defaultApi;

/// Sets default API.
///
/// @param api An API object to be set as default.
///
+ (void)setDefaultApi:(id <MMTApi>)api;

/// Creates API for the given Site.
///
/// @param site The name of the Site.
///
/// @return API object linked with the given Site.
///
+ (id <MMTApi>)apiForSite:(NSString *)site;

/// Sets logger to be used by SDK.
///
/// @param logger Logger to use.
///
+ (void)setLogger:(id <MMTLogger>)logger;

/// Sets logging level.
///
/// @param level Logging level.
///
+ (void)setLogLevel:(MMTLogLevel)level;

/// Turns on/off elements IDs output
///
/// @param printIDs YES to turn on, NO to turn off.
///
+ (void)setPrintElementsIDs:(BOOL)printIDs;

/// Starts SDK in UIKit approach mode for the site.
///
///@param site The name of the Site.
///@param options Start options. See MMTAppOption constants for details.
///@param handler A block that will be invoked once started.
///
+ (void)startForSite:(NSString *)site options:(NSDictionary *)options handler:(void (^)())handler;


/// Fetches new experiences from the Maxymiser platform using the options used in + startForSite: options: handler.
/// Fetching will be performed on a background thread.
///
///@param handler A block that will be invoked once experiences are fetched.
///
+ (void)fetchExperiences:(void (^)())handler;

/// Stops SDK.
///
+ (void)stop;

/// Forces UI transformations on a controller's view.
/// Should be used to apply experiences on dynamic controllers that change their views layout in runtime.
///
///@param controller UIViewController to apply experiences on.
///
+ (void)applyOnController:(UIViewController *)controller;

/// Sets user attribute.
///
///@param name Name of the attribute. Please ensure that PC with this name exist.
///@param value Attribute value.
///
+ (void)setUserAttribute:(NSString *)name value:(NSString *)value;

/// Sets user attribute.
///
///@param name Name of the attribute. Please ensure that PC with this name exist.
///@param block Block that will be invoked to get the attribute value.
///
+ (void)setUserAttribute:(NSString *)name block:(NSString *(^)())block;

/// Sets user ID
///
///@param id User ID.
///
+ (void)setUserId:(NSString *)id;

/// Starts Editor
///
+ (void)startEditor;

/// Stops Editor
///
+ (void)stopEditor;

@end