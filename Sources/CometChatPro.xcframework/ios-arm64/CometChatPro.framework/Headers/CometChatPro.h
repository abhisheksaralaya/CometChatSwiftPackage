#ifndef COMETCHATPRO_SWIFT_H
#define COMETCHATPRO_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="CometChatPro",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif


SWIFT_CLASS("_TtC12CometChatPro9AppEntity")
@interface AppEntity : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSString;
@class NSNumber;
enum MessageType : NSInteger;
enum ReceiverType : NSInteger;
@class MessageReceipt;
enum MessageCategory : NSInteger;
@class User;

SWIFT_CLASS("_TtC12CometChatPro11BaseMessage")
@interface BaseMessage : AppEntity
@property (nonatomic, copy) NSDictionary<NSString *, id> * _Nullable rawMessage;
@property (nonatomic) NSInteger id;
@property (nonatomic, copy) NSString * _Nonnull muid;
@property (nonatomic, copy) NSString * _Nonnull senderUid;
@property (nonatomic, copy) NSString * _Nonnull receiverUid;
@property (nonatomic) enum MessageType messageType;
@property (nonatomic) enum ReceiverType receiverType;
@property (nonatomic, copy) NSArray<MessageReceipt *> * _Nonnull receipts;
@property (nonatomic) double deliveredToMeAt;
@property (nonatomic) double readByMeAt;
@property (nonatomic) double deliveredAt;
@property (nonatomic) double readAt;
@property (nonatomic) NSInteger sentAt;
@property (nonatomic) double updatedAt;
@property (nonatomic, copy) NSString * _Nonnull status;
@property (nonatomic) enum MessageCategory messageCategory;
@property (nonatomic, strong) User * _Nullable sender;
@property (nonatomic, strong) AppEntity * _Nullable receiver;
@property (nonatomic, copy) NSDictionary<NSString *, id> * _Nullable metaData;
@property (nonatomic) double editedAt;
@property (nonatomic, copy) NSString * _Nonnull editedBy;
@property (nonatomic) double deletedAt;
@property (nonatomic, copy) NSString * _Nonnull deletedBy;
@property (nonatomic, copy) NSString * _Nonnull conversationId;
@property (nonatomic) NSInteger parentMessageId;
@property (nonatomic) NSInteger replyCount;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid messageType:(enum MessageType)messageType receiverType:(enum ReceiverType)receiverType OBJC_DESIGNATED_INITIALIZER;
@end

enum GroupMemberScopeType : NSInteger;

/// Action messages are received for real-time group events. The action message class has the following variables.
SWIFT_CLASS("_TtC12CometChatPro13ActionMessage")
@interface ActionMessage : BaseMessage
/// actionBy defines action taken by the user.
@property (nonatomic, strong) AppEntity * _Nullable actionBy;
/// actionFor defines action taken for the user.
@property (nonatomic, strong) AppEntity * _Nullable actionFor;
/// actionOn defines action taken on the group.
@property (nonatomic, strong) AppEntity * _Nullable actionOn;
/// message defines the action taken.
@property (nonatomic, copy) NSString * _Nullable message;
/// message defines the message for the action taken.
@property (nonatomic, copy) NSString * _Nullable rawData;
/// oldScope defines the older scope of the user in the group.
@property (nonatomic) enum GroupMemberScopeType oldScope;
/// newScope defines the new scope of the user in the group.
@property (nonatomic) enum GroupMemberScopeType newScope;
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid messageType:(enum MessageType)messageType receiverType:(enum ReceiverType)receiverType SWIFT_UNAVAILABLE;
/// This method will provide you a string representation of ActionMessageObject.
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
@end


@class AppSettingsBuilder;

SWIFT_CLASS("_TtC12CometChatPro11AppSettings")
@interface AppSettings : NSObject
- (nonnull instancetype)initWithBuilder:(AppSettingsBuilder * _Nonnull)builder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtCC12CometChatPro11AppSettings18AppSettingsBuilder")
@interface AppSettingsBuilder : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (AppSettingsBuilder * _Nonnull)subscribePresenceForAllUsers SWIFT_WARN_UNUSED_RESULT;
- (AppSettingsBuilder * _Nonnull)subscribePresenceForFriends SWIFT_WARN_UNUSED_RESULT;
- (AppSettingsBuilder * _Nonnull)setRegionWithRegion:(NSString * _Nonnull)region SWIFT_WARN_UNUSED_RESULT;
- (AppSettingsBuilder * _Nonnull)subcribePresenceForRolesWithRoles:(NSArray<NSString *> * _Nonnull)roles SWIFT_WARN_UNUSED_RESULT;
- (AppSettingsBuilder * _Nonnull)setEnableAutoJoinForGroupsWithEnableAutoJoinForGroups:(BOOL)enableAutoJoinForGroups SWIFT_WARN_UNUSED_RESULT;
- (AppSettings * _Nonnull)build SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC12CometChatPro10Attachment")
@interface Attachment : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull fileName;
@property (nonatomic, readonly, copy) NSString * _Nonnull fileExtension;
@property (nonatomic, readonly) double fileSize;
@property (nonatomic, readonly, copy) NSString * _Nonnull fileMimeType;
@property (nonatomic, readonly, copy) NSString * _Nonnull fileUrl;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12CometChatPro11AudioDevice")
@interface AudioDevice : AppEntity
@property (nonatomic, copy) NSString * _Nullable mode;
@property (nonatomic) BOOL isSelected;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class BannedGroupMembersRequestBuilder;
@class GroupMember;
@class CometChatException;

SWIFT_CLASS("_TtC12CometChatPro25BannedGroupMembersRequest")
@interface BannedGroupMembersRequest : NSObject
- (nonnull instancetype)initWithBuilder:(BannedGroupMembersRequestBuilder * _Nonnull)builder OBJC_DESIGNATED_INITIALIZER;
- (void)fetchNextOnSuccess:(void (^ _Nonnull)(NSArray<GroupMember *> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtCC12CometChatPro25BannedGroupMembersRequest32BannedGroupMembersRequestBuilder")
@interface BannedGroupMembersRequestBuilder : NSObject
- (nonnull instancetype)initWithGuid:(NSString * _Nonnull)guid OBJC_DESIGNATED_INITIALIZER;
- (BannedGroupMembersRequestBuilder * _Nonnull)setWithLimit:(NSInteger)limit SWIFT_WARN_UNUSED_RESULT;
- (BannedGroupMembersRequestBuilder * _Nonnull)setWithSearchKeyword:(NSString * _Nonnull)searchKeyword SWIFT_WARN_UNUSED_RESULT;
- (BannedGroupMembersRequest * _Nonnull)build SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


enum BaseMessageTypes : NSInteger;

@interface BaseMessage (SWIFT_EXTENSION(CometChatPro))
@property (nonatomic, readonly) enum BaseMessageTypes messgeTypeFromBaseMessage;
@end

typedef SWIFT_ENUM(NSInteger, BaseMessageTypes, open) {
  BaseMessageTypesTextMessage = 0,
  BaseMessageTypesMediaMessage = 1,
  BaseMessageTypesActionMessage = 2,
  BaseMessageTypesCall = 3,
  BaseMessageTypesCustomMessage = 4,
  BaseMessageTypesNone = 5,
};

@class BlockedUserRequestBuilder;

SWIFT_CLASS("_TtC12CometChatPro18BlockedUserRequest")
@interface BlockedUserRequest : NSObject
- (nonnull instancetype)initWithBuilder:(BlockedUserRequestBuilder * _Nonnull)builder OBJC_DESIGNATED_INITIALIZER;
- (void)fetchPreviousOnSuccess:(void (^ _Nonnull)(NSArray<User *> * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
- (void)fetchNextOnSuccess:(void (^ _Nonnull)(NSArray<User *> * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

enum Blocked : NSInteger;

SWIFT_CLASS("_TtCC12CometChatPro18BlockedUserRequest25BlockedUserRequestBuilder")
@interface BlockedUserRequestBuilder : NSObject
- (nonnull instancetype)initWithLimit:(NSInteger)limit OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (BlockedUserRequestBuilder * _Nonnull)setWithLimit:(NSInteger)limit SWIFT_WARN_UNUSED_RESULT;
- (BlockedUserRequestBuilder * _Nonnull)setWithDirection:(enum Blocked)direction SWIFT_WARN_UNUSED_RESULT;
- (BlockedUserRequest * _Nonnull)build SWIFT_WARN_UNUSED_RESULT;
@end

enum callStatus : NSInteger;
enum CallType : NSInteger;

SWIFT_CLASS("_TtC12CometChatPro4Call")
@interface Call : BaseMessage
@property (nonatomic, copy) NSString * _Nullable sessionID;
@property (nonatomic) enum callStatus callStatus;
@property (nonatomic) enum CallType callType;
@property (nonatomic, copy) NSString * _Nullable action;
@property (nonatomic, copy) NSString * _Nullable rawData;
@property (nonatomic) double initiatedAt;
@property (nonatomic) double joinedAt;
@property (nonatomic, strong) AppEntity * _Nullable callInitiator;
@property (nonatomic, strong) AppEntity * _Nullable callReceiver;
- (nonnull instancetype)initWithReceiverId:(NSString * _Nonnull)receiverId callType:(enum CallType)callType receiverType:(enum ReceiverType)receiverType OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid messageType:(enum MessageType)messageType receiverType:(enum ReceiverType)receiverType SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC12CometChatPro11CallManager")
@interface CallManager : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class CallSettingsBuilder;

SWIFT_CLASS("_TtC12CometChatPro12CallSettings")
@interface CallSettings : NSObject
- (nonnull instancetype)initWithBuilder:(CallSettingsBuilder * _Nonnull)builder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class UIView;
enum AudioMode : NSInteger;
enum CallMode : NSInteger;

SWIFT_CLASS("_TtCC12CometChatPro12CallSettings19CallSettingsBuilder")
@interface CallSettingsBuilder : NSObject
- (nonnull instancetype)initWithCallView:(UIView * _Nonnull)callView sessionId:(NSString * _Nonnull)sessionId OBJC_DESIGNATED_INITIALIZER;
- (CallSettingsBuilder * _Nonnull)enableDefaultLayoutWithDefaultLayout:(BOOL)defaultLayout SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)setSessionIdWithSessionId:(NSString * _Nonnull)sessionId SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)showEndCallButtonWithShowEndCallButton:(BOOL)showEndCallButton SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)showSwitchCameraButtonWithShowSwitchCameraButton:(BOOL)showSwitchCameraButton SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)showMuteAudioButtonWithShowMuteAudioButton:(BOOL)showMuteAudioButton SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)showPauseVideoButtonWithShowPauseVideoButton:(BOOL)showPauseVideoButton SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)showAudioModeButtonWithShowAudioModeButton:(BOOL)showAudioModeButton SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)setAudioOnlyCallWithAudioOnly:(BOOL)audioOnly SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)startWithAudioMutedWithAudioMuted:(BOOL)audioMuted SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)startWithVideoMutedWithVideoMuted:(BOOL)videoMuted SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)setDefaultAudioModeWithMode:(enum AudioMode)mode SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)setRegionWithRegion:(NSString * _Nonnull)region SWIFT_WARN_UNUSED_RESULT;
- (CallSettingsBuilder * _Nonnull)setModeWithMode:(enum CallMode)mode SWIFT_WARN_UNUSED_RESULT;
- (CallSettings * _Nonnull)build SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12CometChatPro9CometChat")
@interface CometChat : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) BOOL isInitialised;)
+ (BOOL)isInitialised SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (nonnull instancetype)initWithAppId:(NSString * _Nonnull)appId onSuccess:(void (^ _Nonnull)(BOOL))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nonnull))onError OBJC_DESIGNATED_INITIALIZER SWIFT_AVAILABILITY(ios,unavailable,message="This method is deprecated now. Please use new method `init(appId:String, appSettings : AppSettings,onSuccess:@escaping(_ isSuccess:Bool)-> Void, onError:@escaping (_ error:CometChatException) -> Void )`");
- (nonnull instancetype)initWithAppId:(NSString * _Nonnull)appId appSettings:(AppSettings * _Nonnull)appSettings onSuccess:(void (^ _Nonnull)(BOOL))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nonnull))onError OBJC_DESIGNATED_INITIALIZER;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, groupType, open) {
  groupTypePublic = 0,
  groupTypePrivate = 1,
  groupTypePassword = 2,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)setSourceWithResource:(NSString * _Nonnull)resource platform:(NSString * _Nonnull)platform language:(NSString * _Nonnull)language;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, ConnectionStatus, open) {
  ConnectionStatusConnecting = 0,
  ConnectionStatusConnected = 1,
  ConnectionStatusDisconnected = 2,
  ConnectionStatusOnfeatureThrottled = 3,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, Blocked, open) {
  BlockedByMe = 0,
  BlockedMe = 1,
  BlockedBoth = 2,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)getUserWithUID:(NSString * _Nonnull)UID onSuccess:(void (^ _Nonnull)(User * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
@end



@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, CallMode, open) {
  CallModeMODE_SPOTLIGHT = 0,
  CallModeMODE_SINGLE = 1,
  CallModeMODE_DEFAULT = 2,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, MessageType, open) {
  MessageTypeText = 0,
  MessageTypeImage = 1,
  MessageTypeVideo = 2,
  MessageTypeAudio = 3,
  MessageTypeFile = 4,
  MessageTypeCustom = 5,
  MessageTypeGroupMember = 6,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, ModeCategory, open) {
  ModeCategoryDefault = 0,
  ModeCategoryLimitedTransient = 1,
  ModeCategoryNoTransient = 2,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, SubscriptionType, open) {
  SubscriptionTypeAllUsers = 0,
  SubscriptionTypeOnlyFriends = 1,
  SubscriptionTypeRole = 2,
  SubscriptionTypeNone = 3,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, GroupMemberScopeType, open) {
  GroupMemberScopeTypeAdmin = 0,
  GroupMemberScopeTypeModerator = 1,
  GroupMemberScopeTypeParticipant = 2,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, UserStatus, open) {
  UserStatusOnline = 0,
  UserStatusOffline = 1,
  UserStatusAvailable = 2,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, FeatureType, open) {
  FeatureTypeCore_call_enabled = 0,
  FeatureTypeCore_chat_enabled = 1,
  FeatureTypeFeatures_ue_enabled = 2,
  FeatureTypeFeatures_ux_enabled = 3,
  FeatureTypeIntegrations_enabled = 4,
  FeatureTypeFeatures_bots_enabled = 5,
  FeatureTypeFeatures_data_enabled = 6,
  FeatureTypeCore_chat_groups_enabled = 7,
  FeatureTypeFeatures_ue_polls_enabled = 8,
  FeatureTypeFeatures_webhooks_enabled = 9,
  FeatureTypeFeatures_ue_emojis_enabled = 10,
  FeatureTypeCore_call_recording_enabled = 11,
  FeatureTypeFeatures_moderation_enabled = 12,
  FeatureTypeIntegrations_ui_kit_enabled = 13,
  FeatureTypeCore_call_transcript_enabled = 14,
  FeatureTypeCore_chat_one_on_one_enabled = 15,
  FeatureTypeCore_chat_users_list_enabled = 16,
  FeatureTypeFeatures_ue_mentions_enabled = 17,
  FeatureTypeFeatures_ue_stickers_enabled = 18,
  FeatureTypeCore_chat_voice_notes_enabled = 19,
  FeatureTypeFeatures_ue_reactions_enabled = 20,
  FeatureTypeCore_call_groups_audio_enabled = 21,
  FeatureTypeCore_call_groups_video_enabled = 22,
  FeatureTypeCore_chat_users_search_enabled = 23,
  FeatureTypeFeatures_collaboration_enabled = 24,
  FeatureTypeFeatures_notifications_enabled = 25,
  FeatureTypeCore_chat_groups_public_enabled = 26,
  FeatureTypeCore_chat_groups_search_enabled = 27,
  FeatureTypeIntegrations_client_sdk_enabled = 28,
  FeatureTypeCore_call_live_streaming_enabled = 29,
  FeatureTypeCore_chat_groups_private_enabled = 30,
  FeatureTypeCore_chat_messages_media_enabled = 31,
  FeatureTypeCore_chat_users_presence_enabled = 32,
  FeatureTypeFeatures_ux_link_preview_enabled = 33,
  FeatureTypeIntegrations_chat_widget_enabled = 34,
  FeatureTypeCore_chat_groups_password_enabled = 35,
  FeatureTypeCore_chat_messages_custom_enabled = 36,
  FeatureTypeCore_chat_messages_search_enabled = 37,
  FeatureTypeFeatures_ue_email_replies_enabled = 38,
  FeatureTypeFeatures_ue_smart_replies_enabled = 39,
  FeatureTypeCore_call_one_on_one_audio_enabled = 40,
  FeatureTypeCore_call_one_on_one_video_enabled = 41,
  FeatureTypeCore_chat_messages_history_enabled = 42,
  FeatureTypeCore_chat_messages_replies_enabled = 43,
  FeatureTypeCore_chat_typing_indicator_enabled = 44,
  FeatureTypeFeatures_ue_live_reactions_enabled = 45,
  FeatureTypeFeatures_ux_messages_saved_enabled = 46,
  FeatureTypeCore_chat_messages_receipts_enabled = 47,
  FeatureTypeFeatures_ux_messages_pinned_enabled = 48,
  FeatureTypeFeatures_moderation_groups_ban_enabled = 49,
  FeatureTypeFeatures_moderation_xss_filter_enabled = 50,
  FeatureTypeFeatures_ux_rich_media_preview_enabled = 51,
  FeatureTypeCore_chat_messages_unread_count_enabled = 52,
  FeatureTypeFeatures_collaboration_document_enabled = 53,
  FeatureTypeFeatures_moderation_groups_kick_enabled = 54,
  FeatureTypeFeatures_moderation_users_block_enabled = 55,
  FeatureTypeFeatures_ue_message_translation_enabled = 56,
  FeatureTypeFeatures_ux_voice_transcription_enabled = 57,
  FeatureTypeFeatures_moderation_data_masking_enabled = 58,
  FeatureTypeFeatures_ux_thumbnail_generation_enabled = 59,
  FeatureTypeFeatures_collaboration_whiteboard_enabled = 60,
  FeatureTypeFeatures_data_cross_platform_sync_enabled = 61,
  FeatureTypeFeatures_data_multi_device_support_enabled = 62,
  FeatureTypeFeatures_moderation_malware_scanner_enabled = 63,
  FeatureTypeFeatures_moderation_image_moderation_enabled = 64,
  FeatureTypeFeatures_moderation_profanity_filter_enabled = 65,
  FeatureTypeFeatures_moderation_groups_moderators_enabled = 66,
  FeatureTypeFeatures_moderation_sentiment_analysis_enabled = 67,
  FeatureTypeFeatures_notifications_sms_notification_enabled = 68,
  FeatureTypeFeatures_notifications_push_notification_enabled = 69,
  FeatureTypeFeatures_notifications_email_notification_enabled = 70,
  FeatureTypeFeatures_moderation_inflight_message_moderation_enabled = 71,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, CallType, open) {
  CallTypeAudio = 0,
  CallTypeVideo = 1,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, CallFlowMode, open) {
  CallFlowModeDEFAULT = 0,
  CallFlowModeDIRECT = 1,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, MemberScope, open) {
  MemberScopeAdmin = 0,
  MemberScopeModerator = 1,
  MemberScopeParticipant = 2,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, ConversationType, open) {
  ConversationTypeUser = 0,
  ConversationTypeGroup = 1,
  ConversationTypeNone = 2,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, callStatus, open) {
  callStatusInitiated = 0,
  callStatusOngoing = 1,
  callStatusUnanswered = 2,
  callStatusRejected = 3,
  callStatusBusy = 4,
  callStatusCancelled = 5,
  callStatusEnded = 6,
};



@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, AudioMode, open) {
  AudioModeSPEAKER = 0,
  AudioModeEARPIECE = 1,
  AudioModeHEADPHONES = 2,
  AudioModeBLUETOOTH = 3,
};


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, MessageCategory, open) {
  MessageCategoryMessage = 0,
  MessageCategoryAction = 1,
  MessageCategoryCall = 2,
  MessageCategoryCustom = 3,
};

@class TransientMessage;

@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)sendTransientMessageWithMessage:(TransientMessage * _Nonnull)message;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)isFeatureEnabledWithFeature:(NSString * _Nonnull)feature onSuccess:(void (^ _Nonnull)(BOOL))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
@end



@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, ActionEntityType, open) {
  ActionEntityTypeUser = 0,
  ActionEntityTypeGroup = 1,
  ActionEntityTypeGroupMember = 2,
  ActionEntityTypeMessage = 3,
};

typedef SWIFT_ENUM(NSInteger, actionType, open) {
  actionTypeJoined = 0,
  actionTypeLeft = 1,
  actionTypeKicked = 2,
  actionTypeBanned = 3,
  actionTypeUnbanned = 4,
  actionTypeScopeChanged = 5,
  actionTypeMessageEdited = 6,
  actionTypeMessageDeleted = 7,
  actionTypeAdded = 8,
};

@class Conversation;

@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)getConversationWithConversationWith:(NSString * _Nonnull)conversationWith conversationType:(enum ConversationType)conversationType onSuccess:(void (^ _Nonnull)(Conversation * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)deleteConversationWithConversationWith:(NSString * _Nonnull)conversationWith conversationType:(enum ConversationType)conversationType onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
@end

typedef SWIFT_ENUM(NSInteger, ReceiverType, open) {
  ReceiverTypeUser = 0,
  ReceiverTypeGroup = 1,
};

typedef SWIFT_ENUM(NSInteger, XMPPMsgType, open) {
  XMPPMsgTypeChat = 0,
  XMPPMsgTypeGroupChat = 1,
};

@class TypingIndicator;

@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)startTypingWithIndicator:(TypingIndicator * _Nonnull)indicator;
+ (void)endTypingWithIndicator:(TypingIndicator * _Nonnull)indicator;
@end



@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)kickGroupMemberWithUID:(NSString * _Nonnull)UID GUID:(NSString * _Nonnull)GUID onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)banGroupMemberWithUID:(NSString * _Nonnull)UID GUID:(NSString * _Nonnull)GUID onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)unbanGroupMemberWithUID:(NSString * _Nonnull)UID GUID:(NSString * _Nonnull)GUID onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)updateGroupMemberScopeWithUID:(NSString * _Nonnull)UID GUID:(NSString * _Nonnull)GUID scope:(enum MemberScope)scope onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)processMessage:(NSDictionary<NSString *, id> * _Nonnull)message onSuccess:(void (^ _Nonnull)(BaseMessage * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nonnull))onError;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)markAsReadWithBaseMessage:(BaseMessage * _Nonnull)baseMessage;
+ (void)markAsReadWithMessageId:(NSInteger)messageId receiverId:(NSString * _Nonnull)receiverId receiverType:(enum ReceiverType)receiverType messageSender:(NSString * _Nonnull)messageSender;
+ (void)markAsDeliveredWithBaseMessage:(BaseMessage * _Nonnull)baseMessage;
+ (void)markAsDeliveredWithMessageId:(NSInteger)messageId receiverId:(NSString * _Nonnull)receiverId receiverType:(enum ReceiverType)receiverType messageSender:(NSString * _Nonnull)messageSender;
@end

@class TextMessage;
@class MediaMessage;
@class CustomMessage;

@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)sendTextMessageWithMessage:(TextMessage * _Nonnull)message onSuccess:(void (^ _Nonnull)(TextMessage * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)sendMediaMessageWithMessage:(MediaMessage * _Nonnull)message onSuccess:(void (^ _Nonnull)(MediaMessage * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)sendCustomMessageWithMessage:(CustomMessage * _Nonnull)message onSuccess:(void (^ _Nonnull)(CustomMessage * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)createUserWithUser:(User * _Nonnull)user apiKey:(NSString * _Nonnull)apiKey onSuccess:(void (^ _Nonnull)(User * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)createUserWithUser:(User * _Nonnull)user authKey:(NSString * _Nonnull)authKey onSuccess:(void (^ _Nonnull)(User * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)updateUserWithUser:(User * _Nonnull)user apiKey:(NSString * _Nonnull)apiKey onSuccess:(void (^ _Nonnull)(User * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)updateUserWithUser:(User * _Nonnull)user authKey:(NSString * _Nonnull)authKey onSuccess:(void (^ _Nonnull)(User * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)updateCurrentUserDetailsWithUser:(User * _Nonnull)user onSuccess:(void (^ _Nonnull)(User * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)loginWithUID:(NSString * _Nonnull)UID apiKey:(NSString * _Nonnull)apiKey onSuccess:(void (^ _Nonnull)(User * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nonnull))onError;
+ (void)loginWithUID:(NSString * _Nonnull)UID authKey:(NSString * _Nonnull)authKey onSuccess:(void (^ _Nonnull)(User * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nonnull))onError;
+ (void)loginWithAuthToken:(NSString * _Nonnull)authToken onSuccess:(void (^ _Nonnull)(User * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nonnull))onError;
+ (void)logoutOnSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nonnull))onError;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)initiateCallWithCall:(Call * _Nonnull)call onSuccess:(void (^ _Nonnull)(Call * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)acceptCallWithSessionID:(NSString * _Nonnull)sessionID onSuccess:(void (^ _Nonnull)(Call * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)rejectCallWithSessionID:(NSString * _Nonnull)sessionID status:(enum callStatus)status onSuccess:(void (^ _Nonnull)(Call * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)endCallWithSessionID:(NSString * _Nonnull)sessionID onSuccess:(void (^ _Nonnull)(Call * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)startCallWithSessionID:(NSString * _Nonnull)sessionID inView:(UIView * _Nonnull)inView onUserJoined:(void (^ _Nonnull)(User * _Nullable))onUserJoined onUserLeft:(void (^ _Nonnull)(User * _Nullable))onUserLeft onUserListUpdated:(void (^ _Nonnull)(NSArray<User *> * _Nullable))onUserListUpdated onAudioModesUpdated:(void (^ _Nonnull)(NSArray<AudioDevice *> * _Nullable))onAudioModesUpdated onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError onCallEnded:(void (^ _Nonnull)(Call * _Nullable))onCallEnded;
+ (void)startCallWithCallSettings:(CallSettings * _Nonnull)callSettings onUserJoined:(void (^ _Nonnull)(User * _Nullable))onUserJoined onUserLeft:(void (^ _Nonnull)(User * _Nullable))onUserLeft onUserListUpdated:(void (^ _Nonnull)(NSArray<User *> * _Nullable))onUserListUpdated onAudioModesUpdated:(void (^ _Nonnull)(NSArray<AudioDevice *> * _Nullable))onAudioModesUpdated onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError onCallEnded:(void (^ _Nonnull)(Call * _Nullable))onCallEnded;
+ (Call * _Nullable)getActiveCall SWIFT_WARN_UNUSED_RESULT;
+ (void)getCallParticipantCountWithSessionId:(NSString * _Nonnull)sessionId type:(enum CallFlowMode)type onSuccess:(void (^ _Nonnull)(NSInteger))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
@end

@class Group;

@interface CometChat (SWIFT_EXTENSION(CometChatPro))
+ (void)updateGroupWithGroup:(Group * _Nonnull)group onSuccess:(void (^ _Nonnull)(Group * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)deleteGroupWithGUID:(NSString * _Nonnull)GUID onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)createGroupWithGroup:(Group * _Nonnull)group onSuccess:(void (^ _Nonnull)(Group * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)joinGroupWithGUID:(NSString * _Nonnull)GUID groupType:(enum groupType)groupType password:(NSString * _Nullable)password onSuccess:(void (^ _Nonnull)(Group * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)getGroupWithGUID:(NSString * _Nonnull)GUID onSuccess:(void (^ _Nonnull)(Group * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)leaveGroupWithGUID:(NSString * _Nonnull)GUID onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)getJoinedGroupsOnSuccess:(void (^ _Nonnull)(NSArray<NSString *> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)transferGroupOwnershipWithUID:(NSString * _Nonnull)UID GUID:(NSString * _Nonnull)GUID onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
@end

@protocol CometChatMessageDelegate;
@protocol CometChatCallDelegate;
@protocol CometChatUserDelegate;
@protocol CometChatGroupDelegate;
@protocol CometChatConnectionDelegate;
@protocol CometChatLoginDelegate;

@interface CometChat (SWIFT_EXTENSION(CometChatPro))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, weak) id <CometChatMessageDelegate> _Nullable messagedelegate;)
+ (id <CometChatMessageDelegate> _Nullable)messagedelegate SWIFT_WARN_UNUSED_RESULT;
+ (void)setMessagedelegate:(id <CometChatMessageDelegate> _Nullable)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, weak) id <CometChatCallDelegate> _Nullable calldelegate;)
+ (id <CometChatCallDelegate> _Nullable)calldelegate SWIFT_WARN_UNUSED_RESULT;
+ (void)setCalldelegate:(id <CometChatCallDelegate> _Nullable)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, weak) id <CometChatUserDelegate> _Nullable userdelegate;)
+ (id <CometChatUserDelegate> _Nullable)userdelegate SWIFT_WARN_UNUSED_RESULT;
+ (void)setUserdelegate:(id <CometChatUserDelegate> _Nullable)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, weak) id <CometChatGroupDelegate> _Nullable groupdelegate;)
+ (id <CometChatGroupDelegate> _Nullable)groupdelegate SWIFT_WARN_UNUSED_RESULT;
+ (void)setGroupdelegate:(id <CometChatGroupDelegate> _Nullable)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, weak) id <CometChatConnectionDelegate> _Nullable connectiondelegate;)
+ (id <CometChatConnectionDelegate> _Nullable)connectiondelegate SWIFT_WARN_UNUSED_RESULT;
+ (void)setConnectiondelegate:(id <CometChatConnectionDelegate> _Nullable)value;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, weak) id <CometChatLoginDelegate> _Nullable logindelegate;)
+ (id <CometChatLoginDelegate> _Nullable)logindelegate SWIFT_WARN_UNUSED_RESULT;
+ (void)setLogindelegate:(id <CometChatLoginDelegate> _Nullable)value;
@end


@interface CometChat (SWIFT_EXTENSION(CometChatPro))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) BOOL isCallOngoing;)
+ (BOOL)isCallOngoing SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) Call * _Nullable currentCall;)
+ (Call * _Nullable)currentCall SWIFT_WARN_UNUSED_RESULT;
+ (NSInteger)getLastDeliveredMessageId SWIFT_WARN_UNUSED_RESULT;
+ (User * _Nullable)getLoggedInUser SWIFT_WARN_UNUSED_RESULT;
+ (void)blockUsers:(NSArray<NSString *> * _Nonnull)users onSuccess:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)unblockUsers:(NSArray<NSString *> * _Nonnull)users onSuccess:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)isExtensionEnabledWithExtensionId:(NSString * _Nonnull)extensionId onSuccess:(void (^ _Nonnull)(BOOL))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)getMessageReceipts:(NSInteger)messageId onSuccess:(void (^ _Nonnull)(NSArray<MessageReceipt *> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)getUnreadMessageCountForUser:(NSString * _Nonnull)uid hideMessagesFromBlockedUsers:(BOOL)hideMessagesFromBlockedUsers onSuccess:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)getUnreadMessageCountForGroup:(NSString * _Nonnull)guid hideMessagesFromBlockedUsers:(BOOL)hideMessagesFromBlockedUsers onSuccess:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)getUnreadMessageCountWithHideMessagesFromBlockedUsers:(BOOL)hideMessagesFromBlockedUsers onSuccess:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)getUnreadMessageCountForAllUsersWithHideMessagesFromBlockedUsers:(BOOL)hideMessagesFromBlockedUsers onSuccess:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)getUnreadMessageCountForAllGroupsWithHideMessagesFromBlockedUsers:(BOOL)hideMessagesFromBlockedUsers onSuccess:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)editWithMessage:(BaseMessage * _Nonnull)message onSuccess:(void (^ _Nonnull)(BaseMessage * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nonnull))onError;
+ (void)deleteWithMessageId:(NSInteger)messageId onSuccess:(void (^ _Nonnull)(BaseMessage * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nonnull))onError;
+ (void)addMembersToGroupWithGuid:(NSString * _Nonnull)guid groupMembers:(NSArray<GroupMember *> * _Nonnull)groupMembers bannedUIDs:(NSArray<NSString *> * _Nullable)bannedUIDs onSuccess:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)registerTokenForPushNotificationWithToken:(NSString * _Nonnull)token onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
+ (void)registerTokenForPushNotificationWithToken:(NSString * _Nonnull)token settings:(NSDictionary<NSString *, id> * _Nonnull)settings onSuccess:(void (^ _Nonnull)(NSString * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
@end


SWIFT_PROTOCOL("_TtP12CometChatPro21CometChatCallDelegate_")
@protocol CometChatCallDelegate
- (void)onIncomingCallReceivedWithIncomingCall:(Call * _Nullable)incomingCall error:(CometChatException * _Nullable)error;
- (void)onOutgoingCallAcceptedWithAcceptedCall:(Call * _Nullable)acceptedCall error:(CometChatException * _Nullable)error;
- (void)onOutgoingCallRejectedWithRejectedCall:(Call * _Nullable)rejectedCall error:(CometChatException * _Nullable)error;
- (void)onIncomingCallCancelledWithCanceledCall:(Call * _Nullable)canceledCall error:(CometChatException * _Nullable)error;
@end


SWIFT_PROTOCOL("_TtP12CometChatPro27CometChatConnectionDelegate_")
@protocol CometChatConnectionDelegate
@optional
- (void)connecting;
- (void)connected;
- (void)onfeatureThrottled;
- (void)disconnected;
@end


SWIFT_PROTOCOL("_TtP12CometChatPro11CustomError_")
@protocol CustomError
@property (nonatomic, readonly, copy) NSString * _Nonnull errorDescription;
@property (nonatomic, readonly, copy) NSString * _Nonnull errorCode;
@end


SWIFT_CLASS("_TtC12CometChatPro18CometChatException")
@interface CometChatException : NSObject <CustomError>
@property (nonatomic, copy) NSString * _Nonnull errorDescription;
@property (nonatomic, copy) NSString * _Nonnull errorCode;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


/// This is the base protocol to all the custom CometChatExtensions. This protocol defines certain hooks which can be used to perform specific task. This task will be performed on or before or after certain execution of the events
SWIFT_PROTOCOL("_TtP12CometChatPro18CometChatExtension_")
@protocol CometChatExtension
/// This is to identify the each extension ID uniquely. Format of the Extension ID will similar to bundle identifier.
/// e.g. com.cometchat.<name of the extension>
///
/// returns:
/// returns the extensionID
- (NSString * _Nonnull)getExtensionID SWIFT_WARN_UNUSED_RESULT;
@optional
/// onInit hook will be called when the extensions are added inside the sdk.
/// \param user currently logged-in (inside sdk) User object
///
/// \param appID AppID of the which is registered on CometChat Dashboard.
///
- (void)onInitWithAppID:(NSString * _Nonnull)appID user:(User * _Nullable)user;
/// onLogin hook will be called after the user is LoggedIn inside the sdk.
/// \param user currently logged-in (inside sdk) User object
///
- (void)onLoginWithUser:(User * _Nonnull)user;
/// beforeMessageSent hook will be called just before sending a message to sever.
/// \param message pass a message object of type BaseMessage which you want to send.
///
///
/// returns:
/// It returns a message object of type BaseMessage
- (BaseMessage * _Nonnull)beforeMessageSent:(BaseMessage * _Nonnull)message SWIFT_WARN_UNUSED_RESULT;
/// afterMessageSent hook will be called just after sent the message to server.
/// \param message pass a message object of type BaseMessage which you want to send.
///
///
/// returns:
/// It returns a message object of type BaseMessage
- (BaseMessage * _Nonnull)afterMessageSent:(BaseMessage * _Nonnull)message SWIFT_WARN_UNUSED_RESULT;
/// onMessageReceived hook will be called just after sent the message to server.
/// \param message pass a message object of type BaseMessage which you want to send.
///
///
/// returns:
/// It returns a message object of type BaseMessage
- (BaseMessage * _Nonnull)onMessageReceived:(BaseMessage * _Nonnull)message SWIFT_WARN_UNUSED_RESULT;
/// onMessageListFetched hook will be called just after sent the message to server.
/// \param message pass a message object of type BaseMessage which you want to send.
///
///
/// returns:
/// It returns a message object of type BaseMessage
- (NSArray<BaseMessage *> * _Nonnull)onMessageListFetched:(NSArray<BaseMessage *> * _Nonnull)messages SWIFT_WARN_UNUSED_RESULT;
/// onLogout hook will be called after user hits the logout.
/// <ul>
///   <li>
///     Use: For cleanup and some housekeeping task after logout.
///   </li>
/// </ul>
- (void)onLogout;
@end


SWIFT_PROTOCOL("_TtP12CometChatPro22CometChatGroupDelegate_")
@protocol CometChatGroupDelegate
- (void)onGroupMemberJoinedWithAction:(ActionMessage * _Nonnull)action joinedUser:(User * _Nonnull)joinedUser joinedGroup:(Group * _Nonnull)joinedGroup;
- (void)onGroupMemberLeftWithAction:(ActionMessage * _Nonnull)action leftUser:(User * _Nonnull)leftUser leftGroup:(Group * _Nonnull)leftGroup;
- (void)onGroupMemberKickedWithAction:(ActionMessage * _Nonnull)action kickedUser:(User * _Nonnull)kickedUser kickedBy:(User * _Nonnull)kickedBy kickedFrom:(Group * _Nonnull)kickedFrom;
- (void)onGroupMemberBannedWithAction:(ActionMessage * _Nonnull)action bannedUser:(User * _Nonnull)bannedUser bannedBy:(User * _Nonnull)bannedBy bannedFrom:(Group * _Nonnull)bannedFrom;
- (void)onGroupMemberUnbannedWithAction:(ActionMessage * _Nonnull)action unbannedUser:(User * _Nonnull)unbannedUser unbannedBy:(User * _Nonnull)unbannedBy unbannedFrom:(Group * _Nonnull)unbannedFrom;
- (void)onGroupMemberScopeChangedWithAction:(ActionMessage * _Nonnull)action user:(User * _Nonnull)user scopeChangedTo:(NSString * _Nonnull)scopeChangedTo scopeChangedFrom:(NSString * _Nonnull)scopeChangedFrom group:(Group * _Nonnull)group SWIFT_AVAILABILITY(ios,unavailable,message="This delegate method is deprecated now. Please use new delegate function `onGroupMemberScopeChanged(action: ActionMessage, scopeChangeduser:User, scopeChangedBy : User, scopeChangedTo :String, scopeChangedFrom: String, group: Group)`");
- (void)onGroupMemberScopeChangedWithAction:(ActionMessage * _Nonnull)action scopeChangeduser:(User * _Nonnull)scopeChangeduser scopeChangedBy:(User * _Nonnull)scopeChangedBy scopeChangedTo:(NSString * _Nonnull)scopeChangedTo scopeChangedFrom:(NSString * _Nonnull)scopeChangedFrom group:(Group * _Nonnull)group;
- (void)onAddedToGroupWithAction:(ActionMessage * _Nonnull)action addedBy:(User * _Nonnull)addedBy addedTo:(Group * _Nonnull)addedTo SWIFT_AVAILABILITY(ios,unavailable,message="This delegate method is unavailable now. Please use the delegate function `onMemberAddedToGroup(action: ActionMessage, addedBy : User, addedUser:User ,addedTo:Group)`");
- (void)onMemberAddedToGroupWithAction:(ActionMessage * _Nonnull)action addedBy:(User * _Nonnull)addedBy addedUser:(User * _Nonnull)addedUser addedTo:(Group * _Nonnull)addedTo;
@end


SWIFT_PROTOCOL("_TtP12CometChatPro22CometChatLoginDelegate_")
@protocol CometChatLoginDelegate
- (void)onLoginSuccessWithUser:(User * _Nonnull)user;
- (void)onLoginFailedWithError:(CometChatException * _Nullable)error;
- (void)onLogoutSuccess;
- (void)onLogoutFailedWithError:(CometChatException * _Nullable)error;
@end


SWIFT_PROTOCOL("_TtP12CometChatPro24CometChatMessageDelegate_")
@protocol CometChatMessageDelegate
@optional
- (void)onTextMessageReceivedWithTextMessage:(TextMessage * _Nullable)textMessage error:(CometChatException * _Nullable)error SWIFT_AVAILABILITY(ios,unavailable,message="This delegate method is deprecated now. Please use new delegate function `onTextMessageReceived(textMessage:TextMessage)`");
- (void)onMediaMessageReceivedWithMediaMessage:(MediaMessage * _Nullable)mediaMessage error:(CometChatException * _Nullable)error SWIFT_AVAILABILITY(ios,unavailable,message="This delegate method is deprecated now. Please use new delegate function `onMediaMessageReceived(mediaMessage:MediaMessage)`");
- (void)onCustomMessageReceivedWithCustomMessage:(CustomMessage * _Nullable)customMessage error:(CometChatException * _Nullable)error SWIFT_AVAILABILITY(ios,unavailable,message="This delegate method is deprecated now. Please use new delegate function `onCustomMessageReceived(customMessage:CustomMessage)`");
- (void)onTextMessageReceivedWithTextMessage:(TextMessage * _Nonnull)textMessage;
- (void)onMediaMessageReceivedWithMediaMessage:(MediaMessage * _Nonnull)mediaMessage;
- (void)onCustomMessageReceivedWithCustomMessage:(CustomMessage * _Nonnull)customMessage;
- (void)onTypingStarted:(TypingIndicator * _Nonnull)typingDetails;
- (void)onTypingEnded:(TypingIndicator * _Nonnull)typingDetails;
- (void)onTransisentMessageReceived:(TransientMessage * _Nonnull)message;
- (void)onMessageDeliveredWithReceipt:(MessageReceipt * _Nonnull)receipt SWIFT_AVAILABILITY(ios,unavailable,message="This delegate method is unavailable now. Please use new delegate function `onMessagesDelivered(receipt : MessageReceipt)`");
- (void)onMessageReadWithReceipt:(MessageReceipt * _Nonnull)receipt SWIFT_AVAILABILITY(ios,unavailable,message="This delegate method is unavailable now. Please use new delegate function `onMessagesRead(receipt : MessageReceipt)`");
- (void)onMessageEditedWithMessage:(BaseMessage * _Nonnull)message;
- (void)onMessageDeletedWithMessage:(BaseMessage * _Nonnull)message;
- (void)onMessagesReadWithReceipt:(MessageReceipt * _Nonnull)receipt;
- (void)onMessagesDeliveredWithReceipt:(MessageReceipt * _Nonnull)receipt;
- (void)onMessageReadByAllWithMessageId:(NSString * _Nonnull)messageId receiverId:(NSString * _Nonnull)receiverId receiverType:(enum ReceiverType)receiverType;
- (void)onMessageDeliveredToAllWithMessageId:(NSString * _Nonnull)messageId receiverId:(NSString * _Nonnull)receiverId receiverType:(enum ReceiverType)receiverType;
@end


SWIFT_PROTOCOL("_TtP12CometChatPro21CometChatUserDelegate_")
@protocol CometChatUserDelegate
- (void)onUserOnlineWithUser:(User * _Nonnull)user;
- (void)onUserOfflineWithUser:(User * _Nonnull)user;
@end


SWIFT_CLASS("_TtC12CometChatPro12Conversation")
@interface Conversation : AppEntity
@property (nonatomic, copy) NSString * _Nullable conversationId;
@property (nonatomic) enum ConversationType conversationType;
@property (nonatomic, strong) BaseMessage * _Nullable lastMessage;
@property (nonatomic, strong) AppEntity * _Nullable conversationWith;
@property (nonatomic) NSInteger unreadMessageCount;
@property (nonatomic) double updatedAt;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
@end

@class ConversationRequestBuilder;

SWIFT_CLASS("_TtC12CometChatPro19ConversationRequest")
@interface ConversationRequest : NSObject
- (nonnull instancetype)initWithBuilder:(ConversationRequestBuilder * _Nonnull)builder OBJC_DESIGNATED_INITIALIZER;
- (void)fetchNextOnSuccess:(void (^ _Nonnull)(NSArray<Conversation *> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtCC12CometChatPro19ConversationRequest26ConversationRequestBuilder")
@interface ConversationRequestBuilder : NSObject
- (nonnull instancetype)initWithLimit:(NSInteger)limit OBJC_DESIGNATED_INITIALIZER;
- (ConversationRequestBuilder * _Nonnull)setWithLimit:(NSInteger)limit SWIFT_WARN_UNUSED_RESULT;
- (ConversationRequestBuilder * _Nonnull)setConversationTypeWithConversationType:(enum ConversationType)conversationType SWIFT_WARN_UNUSED_RESULT;
- (ConversationRequestBuilder * _Nonnull)withUserAndGroupTags:(BOOL)withUserAndGroupTags SWIFT_WARN_UNUSED_RESULT;
- (ConversationRequest * _Nonnull)build SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12CometChatPro4User")
@interface User : AppEntity
@property (nonatomic, copy) NSString * _Nullable uid;
@property (nonatomic, copy) NSString * _Nullable name;
@property (nonatomic, copy) NSString * _Nullable avatar;
@property (nonatomic, copy) NSString * _Nullable link;
@property (nonatomic, copy) NSString * _Nullable role;
@property (nonatomic, copy) NSDictionary<NSString *, id> * _Nullable metadata;
@property (nonatomic) enum UserStatus status;
@property (nonatomic, copy) NSString * _Nullable statusMessage;
@property (nonatomic) double lastActiveAt;
@property (nonatomic) BOOL hasBlockedMe;
@property (nonatomic) BOOL blockedByMe;
@property (nonatomic, copy) NSArray<NSString *> * _Nonnull tags;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (nonnull instancetype)initWithUid:(NSString * _Nonnull)uid name:(NSString * _Nonnull)name OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC12CometChatPro11CurrentUser")
@interface CurrentUser : User
- (nonnull instancetype)initWithUid:(NSString * _Nonnull)uid name:(NSString * _Nonnull)name OBJC_DESIGNATED_INITIALIZER;
@end



SWIFT_CLASS("_TtC12CometChatPro13CustomMessage")
@interface CustomMessage : BaseMessage
@property (nonatomic) enum MessageType messageType SWIFT_UNAVAILABLE_MSG("This messageType property of CustomMessage class is obsolete from CometChatPro SDK v1.8.3. Please use new `type` property.");
@property (nonatomic, copy) NSString * _Nullable type;
@property (nonatomic, copy) NSDictionary<NSString *, id> * _Nullable customData;
@property (nonatomic, copy) NSString * _Nullable subType;
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid receiverType:(enum ReceiverType)receiverType customData:(NSDictionary<NSString *, id> * _Nonnull)customData OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid receiverType:(enum ReceiverType)receiverType customData:(NSDictionary<NSString *, id> * _Nonnull)customData type:(NSString * _Nullable)type OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid messageType:(enum MessageType)messageType receiverType:(enum ReceiverType)receiverType SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC12CometChatPro5Group")
@interface Group : AppEntity
@property (nonatomic, copy) NSString * _Nonnull guid;
@property (nonatomic, copy) NSString * _Nullable name;
@property (nonatomic, copy) NSString * _Nullable icon;
@property (nonatomic, copy) NSString * _Nullable groupDescription;
@property (nonatomic, copy) NSString * _Nullable owner;
@property (nonatomic) enum groupType groupType;
@property (nonatomic, copy) NSString * _Nullable password;
@property (nonatomic, copy) NSDictionary<NSString *, id> * _Nullable metadata;
@property (nonatomic) NSInteger createdAt;
@property (nonatomic) NSInteger updatedAt;
@property (nonatomic) NSInteger joinedAt;
@property (nonatomic) enum GroupMemberScopeType scope;
@property (nonatomic) BOOL hasJoined;
@property (nonatomic) NSInteger membersCount;
@property (nonatomic, copy) NSArray<NSString *> * _Nonnull tags;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (nonnull instancetype)initWithGuid:(NSString * _Nonnull)guid name:(NSString * _Nonnull)name groupType:(enum groupType)groupType password:(NSString * _Nullable)password OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithGuid:(NSString * _Nonnull)guid name:(NSString * _Nonnull)name groupType:(enum groupType)groupType password:(NSString * _Nullable)password icon:(NSString * _Nonnull)icon description:(NSString * _Nonnull)description OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC12CometChatPro11GroupMember")
@interface GroupMember : User
@property (nonatomic) enum GroupMemberScopeType scope;
@property (nonatomic) NSInteger joinedAt;
- (nonnull instancetype)initWithUID:(NSString * _Nonnull)UID groupMemberScope:(enum GroupMemberScopeType)groupMemberScope OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithUid:(NSString * _Nonnull)uid name:(NSString * _Nonnull)name SWIFT_UNAVAILABLE;
@end

@class GroupMembersRequestBuilder;

SWIFT_CLASS("_TtC12CometChatPro19GroupMembersRequest")
@interface GroupMembersRequest : NSObject
- (nonnull instancetype)initWithBuilder:(GroupMembersRequestBuilder * _Nonnull)builder OBJC_DESIGNATED_INITIALIZER;
- (void)fetchNextOnSuccess:(void (^ _Nonnull)(NSArray<GroupMember *> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtCC12CometChatPro19GroupMembersRequest26GroupMembersRequestBuilder")
@interface GroupMembersRequestBuilder : NSObject
- (nonnull instancetype)initWithGuid:(NSString * _Nonnull)guid OBJC_DESIGNATED_INITIALIZER;
- (GroupMembersRequestBuilder * _Nonnull)setWithSearchKeyword:(NSString * _Nonnull)searchKeyword SWIFT_WARN_UNUSED_RESULT;
- (GroupMembersRequestBuilder * _Nonnull)setWithLimit:(NSInteger)limit SWIFT_WARN_UNUSED_RESULT;
- (GroupMembersRequestBuilder * _Nonnull)setWithScopes:(NSArray<NSString *> * _Nonnull)scopes SWIFT_WARN_UNUSED_RESULT;
- (GroupMembersRequest * _Nonnull)build SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class GroupsRequestBuilder;

SWIFT_CLASS("_TtC12CometChatPro13GroupsRequest")
@interface GroupsRequest : NSObject
- (nonnull instancetype)initWithBuilder:(GroupsRequestBuilder * _Nonnull)builder OBJC_DESIGNATED_INITIALIZER;
- (void)fetchNextOnSuccess:(void (^ _Nonnull)(NSArray<Group *> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtCC12CometChatPro13GroupsRequest20GroupsRequestBuilder")
@interface GroupsRequestBuilder : NSObject
- (nonnull instancetype)initWithLimit:(NSInteger)limit OBJC_DESIGNATED_INITIALIZER;
- (GroupsRequestBuilder * _Nonnull)setWithLimit:(NSInteger)limit SWIFT_WARN_UNUSED_RESULT;
- (GroupsRequestBuilder * _Nonnull)setWithSearchKeyword:(NSString * _Nonnull)searchKeyword SWIFT_WARN_UNUSED_RESULT;
- (GroupsRequestBuilder * _Nonnull)setWithJoinedOnly:(BOOL)joinedOnly SWIFT_WARN_UNUSED_RESULT;
- (GroupsRequestBuilder * _Nonnull)withTags:(BOOL)withTags SWIFT_WARN_UNUSED_RESULT;
- (GroupsRequestBuilder * _Nonnull)setWithTags:(NSArray<NSString *> * _Nonnull)tags SWIFT_WARN_UNUSED_RESULT;
- (GroupsRequest * _Nonnull)build SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12CometChatPro12MediaMessage")
@interface MediaMessage : BaseMessage
@property (nonatomic, copy) NSString * _Nullable caption;
@property (nonatomic, strong) Attachment * _Nullable attachment;
@property (nonatomic, copy) NSString * _Nonnull filePath;
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid fileurl:(NSString * _Nonnull)fileurl messageType:(enum MessageType)messageType receiverType:(enum ReceiverType)receiverType OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid messageType:(enum MessageType)messageType receiverType:(enum ReceiverType)receiverType SWIFT_UNAVAILABLE;
@end

enum ReceiptType : NSInteger;

SWIFT_CLASS("_TtC12CometChatPro14MessageReceipt")
@interface MessageReceipt : NSObject
@property (nonatomic, copy) NSString * _Nonnull receiverId;
@property (nonatomic) enum ReceiverType receiverType;
@property (nonatomic, copy) NSString * _Nonnull messageId;
@property (nonatomic, strong) User * _Nullable sender;
@property (nonatomic) enum ReceiptType receiptType;
@property (nonatomic) NSInteger timeStamp;
@property (nonatomic) double deliveredAt;
@property (nonatomic) double readAt;
- (nonnull instancetype)initWithMessageId:(NSString * _Nonnull)messageId sender:(User * _Nonnull)sender receiverId:(NSString * _Nonnull)receiverId receiverType:(enum ReceiverType)receiverType receiptType:(enum ReceiptType)receiptType timeStamp:(NSInteger)timeStamp OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

typedef SWIFT_ENUM(NSInteger, ReceiptType, open) {
  ReceiptTypeDelivered = 0,
  ReceiptTypeRead = 1,
};

@class MessageRequestBuilder;

SWIFT_CLASS("_TtC12CometChatPro15MessagesRequest")
@interface MessagesRequest : NSObject
- (nonnull instancetype)initWithBuilder:(MessageRequestBuilder * _Nonnull)builder OBJC_DESIGNATED_INITIALIZER;
- (void)fetchPreviousOnSuccess:(void (^ _Nonnull)(NSArray<BaseMessage *> * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
- (void)fetchNextOnSuccess:(void (^ _Nonnull)(NSArray<BaseMessage *> * _Nullable))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtCC12CometChatPro15MessagesRequest21MessageRequestBuilder")
@interface MessageRequestBuilder : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (MessageRequestBuilder * _Nonnull)setWithLimit:(NSInteger)limit SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setWithGuid:(NSString * _Nonnull)guid SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setWithUid:(NSString * _Nonnull)uid SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setWithTimeStamp:(NSInteger)timeStamp SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setWithMessageID:(NSInteger)messageID SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setWithUnread:(BOOL)unread SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)hideMessagesFromBlockedUsers:(BOOL)block SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setWithSearchKeyword:(NSString * _Nonnull)searchKeyword SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)hideDeletedMessagesWithHide:(BOOL)hide SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setUpdatedAfterTimeStamp:(NSInteger)timeStamp SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)updatesOnlyWithOnlyUpdates:(BOOL)onlyUpdates SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setCategoryWithCategory:(NSString * _Nonnull)category SWIFT_WARN_UNUSED_RESULT SWIFT_AVAILABILITY(ios,deprecated=2.1.2,message="This method is deprecated now. Please use new function `set(categories : [String])`");
- (MessageRequestBuilder * _Nonnull)setWithCategories:(NSArray<NSString *> * _Nonnull)categories SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setTypeWithType:(NSString * _Nonnull)type SWIFT_WARN_UNUSED_RESULT SWIFT_AVAILABILITY(ios,deprecated=2.1.2,message="This method is deprecated now. Please use new function `set(types : [String])`");
- (MessageRequestBuilder * _Nonnull)setWithTypes:(NSArray<NSString *> * _Nonnull)types SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)setParentMessageIdWithParentMessageId:(NSInteger)parentMessageId SWIFT_WARN_UNUSED_RESULT;
- (MessageRequestBuilder * _Nonnull)hideRepliesWithHide:(BOOL)hide SWIFT_WARN_UNUSED_RESULT;
- (MessagesRequest * _Nonnull)build SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC12CometChatPro11TextMessage")
@interface TextMessage : BaseMessage
@property (nonatomic, copy) NSString * _Nonnull text;
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid text:(NSString * _Nonnull)text receiverType:(enum ReceiverType)receiverType OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithReceiverUid:(NSString * _Nonnull)receiverUid messageType:(enum MessageType)messageType receiverType:(enum ReceiverType)receiverType SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC12CometChatPro16TransientMessage")
@interface TransientMessage : NSObject
@property (nonatomic, copy) NSString * _Nonnull receiverID;
@property (nonatomic) enum ReceiverType receiverType;
@property (nonatomic, copy) NSDictionary<NSString *, id> * _Nonnull data;
@property (nonatomic, strong) User * _Nullable sender;
- (nonnull instancetype)initWithReceiverID:(NSString * _Nonnull)receiverID receiverType:(enum ReceiverType)receiverType data:(NSDictionary<NSString *, id> * _Nonnull)data OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC12CometChatPro15TypingIndicator")
@interface TypingIndicator : NSObject
@property (nonatomic, copy) NSString * _Nonnull receiverID;
@property (nonatomic) enum ReceiverType receiverType;
@property (nonatomic, copy) NSDictionary<NSString *, id> * _Nullable metadata;
@property (nonatomic, strong) User * _Nullable sender;
- (nonnull instancetype)initWithReceiverID:(NSString * _Nonnull)receiverID receiverType:(enum ReceiverType)receiverType OBJC_DESIGNATED_INITIALIZER;
- (NSString * _Nonnull)stringValue SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



@class UsersRequestBuilder;

SWIFT_CLASS("_TtC12CometChatPro12UsersRequest")
@interface UsersRequest : NSObject
- (nonnull instancetype)initWithBuilder:(UsersRequestBuilder * _Nonnull)builder OBJC_DESIGNATED_INITIALIZER;
- (void)fetchNextOnSuccess:(void (^ _Nonnull)(NSArray<User *> * _Nonnull))onSuccess onError:(void (^ _Nonnull)(CometChatException * _Nullable))onError;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtCC12CometChatPro12UsersRequest19UsersRequestBuilder")
@interface UsersRequestBuilder : NSObject
- (nonnull instancetype)initWithLimit:(NSInteger)limit OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (UsersRequestBuilder * _Nonnull)setWithLimit:(NSInteger)limit SWIFT_WARN_UNUSED_RESULT;
- (UsersRequestBuilder * _Nonnull)setWithStatus:(enum UserStatus)status SWIFT_WARN_UNUSED_RESULT;
- (UsersRequestBuilder * _Nonnull)setWithSearchKeyword:(NSString * _Nonnull)searchKeyword SWIFT_WARN_UNUSED_RESULT;
- (UsersRequestBuilder * _Nonnull)setWithRole:(NSString * _Nonnull)role SWIFT_WARN_UNUSED_RESULT SWIFT_AVAILABILITY(ios,deprecated=2.1.2,message="This method is deprecated now. Please use new function `set(roles : [String])`");
- (UsersRequestBuilder * _Nonnull)setWithRoles:(NSArray<NSString *> * _Nonnull)roles SWIFT_WARN_UNUSED_RESULT;
- (UsersRequestBuilder * _Nonnull)setWithTags:(NSArray<NSString *> * _Nonnull)tags SWIFT_WARN_UNUSED_RESULT;
- (UsersRequestBuilder * _Nonnull)hideBlockedUsers:(BOOL)hide SWIFT_WARN_UNUSED_RESULT;
- (UsersRequestBuilder * _Nonnull)friendsOnly:(BOOL)friendsOnly SWIFT_WARN_UNUSED_RESULT;
- (UsersRequestBuilder * _Nonnull)withTags:(BOOL)withTags SWIFT_WARN_UNUSED_RESULT;
- (UsersRequestBuilder * _Nonnull)setWithUIDs:(NSArray<NSString *> * _Nonnull)UIDs SWIFT_WARN_UNUSED_RESULT;
- (UsersRequest * _Nonnull)build SWIFT_WARN_UNUSED_RESULT;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif
