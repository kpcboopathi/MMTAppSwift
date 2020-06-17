//
// MMTExperiences.h
// Maxymiser Mobile Testing iOS SDK
//
// Copyright(c) 2005-2014 Maxymiser Ltd, All Rights Reserved.

#import <Foundation/Foundation.h>

@protocol MMTExperiences <NSObject>

/// Retrieves a generated variant name for a campaign and the element which is related to a test configuration in the Maxymiser UI.
///
/// @param campaign Name of the campaign for which you want to get the variant name.
/// @param element Name of the element in the campaign for which you want to get the variant name.
///
/// @return The name of the generated variant for the element in the campaign.
/// Returns nil for the following cases: the campaign is not started, the campaign is finished, the campaign is paused or the site is disabled.
/// In any of these situations a process to render default content should be put in place.
///
- (NSString *)getVariantNameForCampaign:(NSString *)campaign element:(NSString *)element;

/// Retrieves a generated variant content for a campaign and the element which is related to a test configuration in the Maxymiser UI.
///
/// @param campaign Name of the campaign for which you want to get the variant content.
/// @param element Name of the element in the campaign for which you want to get the variant content.
///
/// @return The content of the generated variant for the element in the campaign.
/// Returns nil for the following cases: the campaign is not started, the campaign is finished, the campaign is paused or the site is disabled.
/// In any of these situations a process to render default content should be put in place.
///
- (NSString *)getVariantContentForCampaign:(NSString *)campaign element:(NSString *)element;

@end