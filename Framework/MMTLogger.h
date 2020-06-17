//
// MMTLogger.h
// Maxymiser Mobile Testing iOS SDK
//
// Copyright(c) 2005-2014 Maxymiser Ltd, All Rights Reserved.

typedef NS_ENUM(NSInteger, MMTLogLevel) {
    MMTLogOff = 0,
    MMTLogErrorLevel = 1,
    MMTLogWarningLevel = 2,
    MMTLogInfoLevel = 3,
    MMTLogDebugLevel = 4
};

@protocol MMTLogger <NSObject>

/// Logs message with log level Debug.
///
/// @param message Message to log.
///
- (void)debug:(NSString *)message;

/// Logs message with log level Info.
///
/// @param message Message to log.
///
- (void)info:(NSString *)message;

/// Logs message with log level Warning.
///
/// @param message Message to log.
///
- (void)warning:(NSString *)message;

/// Logs message with log level Error.
///
/// @param message Message to log.
///
- (void)error:(NSString *)message;

/// Prints technical information.
/// Works independently of logger status (even if logger is off).
///
/// @param message Message to log.
///
- (void)print:(NSString *)message;

@end