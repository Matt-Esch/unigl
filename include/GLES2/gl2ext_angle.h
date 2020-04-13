//
// Copyright 2017 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// gl2ext_angle.h: ANGLE modifications to the gl2ext.h header file.
//   Currently we don't include this file directly, we patch gl2ext.h
//   to include it implicitly so it is visible throughout our code.

#ifndef INCLUDE_GLES2_GL2EXT_ANGLE_H_
#define INCLUDE_GLES2_GL2EXT_ANGLE_H_

// clang-format off

#ifndef GL_ANGLE_client_arrays
#define GL_ANGLE_client_arrays 1
#define GL_CLIENT_ARRAYS_ANGLE 0x93AA
#endif /* GL_ANGLE_client_arrays */

#ifndef GL_ANGLE_request_extension
#define GL_ANGLE_request_extension 1
#define GL_REQUESTABLE_EXTENSIONS_ANGLE   0x93A8
#define GL_NUM_REQUESTABLE_EXTENSIONS_ANGLE 0x93A9
typedef void (GL_APIENTRYP PFNGLREQUESTEXTENSIONANGLEPROC) (const GLchar *name);
typedef void (GL_APIENTRYP PFNGLDISABLEEXTENSIONANGLEPROC) (const GLchar *name);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glRequestExtensionANGLE (const GLchar *name);
#endif
#endif /* GL_ANGLE_webgl_compatibility */

#ifndef GL_ANGLE_robust_resource_initialization
#define GL_ANGLE_robust_resource_initialization 1
#define GL_ROBUST_RESOURCE_INITIALIZATION_ANGLE 0x93AB
#endif /* GL_ANGLE_robust_resource_initialization */

#ifndef GL_ANGLE_provoking_vertex
#define GL_ANGLE_provoking_vertex 1
#define GL_FIRST_VERTEX_CONVENTION                   0x8E4D
#define GL_LAST_VERTEX_CONVENTION                    0x8E4E
#define GL_PROVOKING_VERTEX                          0x8E4F
typedef void (GL_APIENTRYP PFNGLPROVOKINGVERTEXANGLEPROC) (GLenum);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glProvokingVertexANGLE(GLenum mode);
#endif
#endif /* GL_ANGLE_provoking_vertex */

#ifndef GL_CHROMIUM_framebuffer_mixed_samples
#define GL_CHROMIUM_frambuffer_mixed_samples 1
#define GL_COVERAGE_MODULATION_CHROMIUM 0x9332
typedef void (GL_APIENTRYP PFNGLCOVERAGEMODULATIONCHROMIUMPROC) (GLenum components);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glCoverageModulationCHROMIUM(GLenum components);
#endif
#endif /* GL_CHROMIUM_framebuffer_mixed_samples */

#ifndef GL_CHROMIUM_bind_generates_resource
#define GL_CHROMIUM_bind_generates_resource 1
#define GL_BIND_GENERATES_RESOURCE_CHROMIUM 0x9244
#endif /* GL_CHROMIUM_bind_generates_resource */

#ifndef GL_ANGLE_memory_size
#define GL_ANGLE_memory_size
#define GL_MEMORY_SIZE_ANGLE 0x93AD
#endif /* GL_ANGLE_memory_size */

// needed by NV_path_rendering (and thus CHROMIUM_path_rendering)
// but CHROMIUM_path_rendering only needs MatrixLoadfEXT, MatrixLoadIdentityEXT
#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1
typedef void(GL_APIENTRYP PFNGLMATRIXLOADFEXTPROC)(GLenum matrixMode, const GLfloat *m);
typedef void(GL_APIENTRYP PFNGLMATRIXLOADIDENTITYEXTPROC)(GLenum matrixMode);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glMatrixLoadfEXT(GLenum matrixMode, const GLfloat *m);
GL_APICALL void GL_APIENTRY glMatrixLoadIdentityEXT(GLenum matrixMode);
#endif
#endif /* GL_EXT_direct_state_access */

#ifndef GL_CHROMIUM_copy_texture
#define GL_CHROMIUM_copy_texture 1
typedef void(GL_APIENTRYP PFNGLCOPYTEXTURECHROMIUMPROC)(GLuint sourceId,
                                                        GLint sourceLevel,
                                                        GLenum destTarget,
                                                        GLuint destId,
                                                        GLint destLevel,
                                                        GLint internalFormat,
                                                        GLenum destType,
                                                        GLboolean unpackFlipY,
                                                        GLboolean unpackPremultiplyAlpha,
                                                        GLboolean unpackUnmultiplyAlpha);
typedef void(GL_APIENTRYP PFNGLCOPYSUBTEXTURECHROMIUMPROC)(GLuint sourceId,
                                                           GLint sourceLevel,
                                                           GLenum destTarget,
                                                           GLuint destId,
                                                           GLint destLevel,
                                                           GLint xoffset,
                                                           GLint yoffset,
                                                           GLint x,
                                                           GLint y,
                                                           GLsizei width,
                                                           GLsizei height,
                                                           GLboolean unpackFlipY,
                                                           GLboolean unpackPremultiplyAlpha,
                                                           GLboolean unpackUnmultiplyAlpha);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glCopyTextureCHROMIUM(GLuint sourceId,
                                                  GLint sourceLevel,
                                                  GLenum destTarget,
                                                  GLuint destId,
                                                  GLint destLevel,
                                                  GLint internalFormat,
                                                  GLenum destType,
                                                  GLboolean unpackFlipY,
                                                  GLboolean unpackPremultiplyAlpha,
                                                  GLboolean unpackUnmultiplyAlpha);
GL_APICALL void GL_APIENTRY glCopySubTextureCHROMIUM(GLuint sourceId,
                                                     GLint sourceLevel,
                                                     GLenum destTarget,
                                                     GLuint destId,
                                                     GLint destLevel,
                                                     GLint xoffset,
                                                     GLint yoffset,
                                                     GLint x,
                                                     GLint y,
                                                     GLsizei width,
                                                     GLsizei height,
                                                     GLboolean unpackFlipY,
                                                     GLboolean unpackPremultiplyAlpha,
                                                     GLboolean unpackUnmultiplyAlpha);
#endif
#endif /* GL_CHROMIUM_copy_texture */

#ifndef GL_CHROMIUM_compressed_copy_texture
#define GL_CHROMIUM_compressed_copy_texture 1
typedef void(GL_APIENTRYP PFNGLCOMPRESSEDCOPYTEXTURECHROMIUMPROC)(GLuint sourceId, GLuint destId);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glCompressedCopyTextureCHROMIUM(GLuint sourceId, GLuint destId);
#endif
#endif /* GL_CHROMIUM_compressed_copy_texture */


#ifndef GL_ANGLE_copy_texture_3d
#define GL_ANGLE_copy_texture_3d 1
typedef void(GL_APIENTRYP PFNGLCOPYTEXTURE3DANGLEPROC)(GLuint sourceId,
                                                        GLint sourceLevel,
                                                        GLenum destTarget,
                                                        GLuint destId,
                                                        GLint destLevel,
                                                        GLint internalFormat,
                                                        GLenum destType,
                                                        GLboolean unpackFlipY,
                                                        GLboolean unpackPremultiplyAlpha,
                                                        GLboolean unpackUnmultiplyAlpha);
typedef void(GL_APIENTRYP PFNGLCOPYSUBTEXTURE3DANGLEPROC)(GLuint sourceId,
                                                           GLint sourceLevel,
                                                           GLenum destTarget,
                                                           GLuint destId,
                                                           GLint destLevel,
                                                           GLint xoffset,
                                                           GLint yoffset,
                                                           GLint zoffset,
                                                           GLint x,
                                                           GLint y,
                                                           GLint z,
                                                           GLsizei width,
                                                           GLsizei height,
                                                           GLsizei depth,
                                                           GLboolean unpackFlipY,
                                                           GLboolean unpackPremultiplyAlpha,
                                                           GLboolean unpackUnmultiplyAlpha);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glCopyTexture3DANGLE(GLuint sourceId,
                                                  GLint sourceLevel,
                                                  GLenum destTarget,
                                                  GLuint destId,
                                                  GLint destLevel,
                                                  GLint internalFormat,
                                                  GLenum destType,
                                                  GLboolean unpackFlipY,
                                                  GLboolean unpackPremultiplyAlpha,
                                                  GLboolean unpackUnmultiplyAlpha);
GL_APICALL void GL_APIENTRY glCopySubTexture3DANGLE(GLuint sourceId,
                                                     GLint sourceLevel,
                                                     GLenum destTarget,
                                                     GLuint destId,
                                                     GLint destLevel,
                                                     GLint xoffset,
                                                     GLint yoffset,
                                                     GLint zoffset,
                                                     GLint x,
                                                     GLint y,
                                                     GLint z,
                                                     GLsizei width,
                                                     GLsizei height,
                                                     GLsizei depth,
                                                     GLboolean unpackFlipY,
                                                     GLboolean unpackPremultiplyAlpha,
                                                     GLboolean unpackUnmultiplyAlpha);
#endif
#endif /* GL_ANGLE_copy_texture_3d */

#ifndef GL_CHROMIUM_sync_query
#define GL_CHROMIUM_sync_query 1
#define GL_COMMANDS_COMPLETED_CHROMIUM    0x84F7
#endif  /* GL_CHROMIUM_sync_query */

#ifndef GL_EXT_texture_compression_s3tc_srgb
#define GL_EXT_texture_compression_s3tc_srgb 1
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT  0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT 0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT 0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT 0x8C4F
#endif /* GL_EXT_texture_compression_s3tc_srgb */

#ifndef GL_ANGLE_lossy_etc_decode
#define GL_ANGLE_lossy_etc_decode 1
#define GL_ETC1_RGB8_LOSSY_DECODE_ANGLE                                  0x9690
#define GL_COMPRESSED_R11_LOSSY_DECODE_EAC_ANGLE                         0x9691
#define GL_COMPRESSED_SIGNED_R11_LOSSY_DECODE_EAC_ANGLE                  0x9692
#define GL_COMPRESSED_RG11_LOSSY_DECODE_EAC_ANGLE                        0x9693
#define GL_COMPRESSED_SIGNED_RG11_LOSSY_DECODE_EAC_ANGLE                 0x9694
#define GL_COMPRESSED_RGB8_LOSSY_DECODE_ETC2_ANGLE                       0x9695
#define GL_COMPRESSED_SRGB8_LOSSY_DECODE_ETC2_ANGLE                      0x9696
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_LOSSY_DECODE_ETC2_ANGLE   0x9697
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_LOSSY_DECODE_ETC2_ANGLE  0x9698
#define GL_COMPRESSED_RGBA8_LOSSY_DECODE_ETC2_EAC_ANGLE                  0x9699
#define GL_COMPRESSED_SRGB8_ALPHA8_LOSSY_DECODE_ETC2_EAC_ANGLE           0x969A
#endif /* GL_ANGLE_lossy_etc_decode */

#ifndef GL_ANGLE_robust_client_memory
#define GL_ANGLE_robust_client_memory 1
typedef void (GL_APIENTRYP PFNGLGETBOOLEANVROBUSTANGLEPROC) (GLenum pname, GLsizei bufSize, GLsizei *length, GLboolean *data);
typedef void (GL_APIENTRYP PFNGLGETBUFFERPARAMETERIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETFLOATVROBUSTANGLEPROC) (GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *data);
typedef void (GL_APIENTRYP PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVROBUSTANGLEPROC) (GLenum target, GLenum attachment, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETINTEGERVROBUSTANGLEPROC) (GLenum pname, GLsizei bufSize, GLsizei *length, GLint *data);
typedef void (GL_APIENTRYP PFNGLGETPROGRAMIVROBUSTANGLEPROC) (GLuint program, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETRENDERBUFFERPARAMETERIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETSHADERIVROBUSTANGLEPROC) (GLuint shader, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETTEXPARAMETERFVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETTEXPARAMETERIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETUNIFORMFVROBUSTANGLEPROC) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETUNIFORMIVROBUSTANGLEPROC) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBFVROBUSTANGLEPROC) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBIVROBUSTANGLEPROC) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVROBUSTANGLEPROC) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, void **pointer);
typedef void (GL_APIENTRYP PFNGLREADPIXELSROBUSTANGLEPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLsizei *length, GLsizei *columns, GLsizei *rows, void *pixels);
typedef void (GL_APIENTRYP PFNGLTEXIMAGE2DROBUSTANGLEPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
typedef void (GL_APIENTRYP PFNGLTEXPARAMETERFVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, const GLfloat *params);
typedef void (GL_APIENTRYP PFNGLTEXPARAMETERIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, const GLint *params);
typedef void (GL_APIENTRYP PFNGLTEXSUBIMAGE2DROBUSTANGLEPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
typedef void (GL_APIENTRYP PFNGLTEXIMAGE3DROBUSTANGLEPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
typedef void (GL_APIENTRYP PFNGLTEXSUBIMAGE3DROBUSTANGLEPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
typedef void (GL_APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DROBUSTANGLEPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLsizei bufSize, const void *data);
typedef void (GL_APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DROBUSTANGLEPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLsizei bufSize, const void *data);
typedef void (GL_APIENTRYP PFNGLCOMPRESSEDTEXIMAGE3DROBUSTANGLEPROC) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLsizei bufSize, const void *data);
typedef void (GL_APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE3DROBUSTANGLEPROC) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLsizei bufSize, const void *data);
typedef void (GL_APIENTRYP PFNGLGETQUERYIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETQUERYOBJECTUIVROBUSTANGLEPROC) (GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETBUFFERPOINTERVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, void **params);
typedef void (GL_APIENTRYP PFNGLGETINTEGERI_VROBUSTANGLEPROC) (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLint *data);
typedef void (GL_APIENTRYP PFNGLGETINTERNALFORMATIVROBUSTANGLEPROC) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBIIVROBUSTANGLEPROC) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETVERTEXATTRIBIUIVROBUSTANGLEPROC) (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETUNIFORMUIVROBUSTANGLEPROC) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETACTIVEUNIFORMBLOCKIVROBUSTANGLEPROC) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETINTEGER64VROBUSTANGLEPROC) (GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *data);
typedef void (GL_APIENTRYP PFNGLGETINTEGER64I_VROBUSTANGLEPROC) (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLint64 *data);
typedef void (GL_APIENTRYP PFNGLGETBUFFERPARAMETERI64VROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *params);
typedef void (GL_APIENTRYP PFNGLSAMPLERPARAMETERIVROBUSTANGLEPROC) (GLuint sampler, GLenum pname, GLsizei bufSize, const GLint *param);
typedef void (GL_APIENTRYP PFNGLSAMPLERPARAMETERFVROBUSTANGLEPROC) (GLuint sampler, GLenum pname, GLsizei bufSize, const GLfloat *param);
typedef void (GL_APIENTRYP PFNGLGETSAMPLERPARAMETERIVROBUSTANGLEPROC) (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETSAMPLERPARAMETERFVROBUSTANGLEPROC) (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETFRAMEBUFFERPARAMETERIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETPROGRAMINTERFACEIVROBUSTANGLEPROC) (GLuint program, GLenum programInterface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETBOOLEANI_VROBUSTANGLEPROC) (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLboolean *data);
typedef void (GL_APIENTRYP PFNGLGETMULTISAMPLEFVROBUSTANGLEPROC) (GLenum pname, GLuint index, GLsizei bufSize, GLsizei *length, GLfloat *val);
typedef void (GL_APIENTRYP PFNGLGETTEXLEVELPARAMETERIVROBUSTANGLEPROC) (GLenum target, GLint level, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETTEXLEVELPARAMETERFVROBUSTANGLEPROC) (GLenum target, GLint level, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETPOINTERVROBUSTANGLEROBUSTANGLEPROC) (GLenum pname, GLsizei bufSize, GLsizei *length, void **params);
typedef void (GL_APIENTRYP PFNGLREADNPIXELSROBUSTANGLEPROC) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLsizei *length, GLsizei *columns, GLsizei *rows, void *data);
typedef void (GL_APIENTRYP PFNGLGETNUNIFORMFVROBUSTANGLEPROC) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLfloat *params);
typedef void (GL_APIENTRYP PFNGLGETNUNIFORMIVROBUSTANGLEPROC) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETNUNIFORMUIVROBUSTANGLEPROC) (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLTEXPARAMETERIIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, const GLint *params);
typedef void (GL_APIENTRYP PFNGLTEXPARAMETERIUIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, const GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETTEXPARAMETERIIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETTEXPARAMETERIUIVROBUSTANGLEPROC) (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLSAMPLERPARAMETERIIVROBUSTANGLEPROC) (GLuint sampler, GLenum pname, GLsizei bufSize, const GLint *param);
typedef void (GL_APIENTRYP PFNGLSAMPLERPARAMETERIUIVROBUSTANGLEPROC) (GLuint sampler, GLenum pname, GLsizei bufSize, const GLuint *param);
typedef void (GL_APIENTRYP PFNGLGETSAMPLERPARAMETERIIVROBUSTANGLEPROC) (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVROBUSTANGLEPROC) (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
typedef void (GL_APIENTRYP PFNGLGETQUERYOBJECTIVROBUSTANGLEPROC)(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETQUERYOBJECTI64VROBUSTANGLEPROC)(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *params);
typedef void (GL_APIENTRYP PFNGLGETQUERYOBJECTUI64VROBUSTANGLEPROC)(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint64 *params);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glGetBooleanvRobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, GLboolean *data);
GL_APICALL void GL_APIENTRY glGetBufferParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetFloatvRobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *data);
GL_APICALL void GL_APIENTRY glGetFramebufferAttachmentParameterivRobustANGLE (GLenum target, GLenum attachment, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetIntegervRobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, GLint *data);
GL_APICALL void GL_APIENTRY glGetProgramivRobustANGLE (GLuint program, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetRenderbufferParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetShaderivRobustANGLE (GLuint shader, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetTexParameterfvRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetTexParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetUniformfvRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetUniformivRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribfvRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribivRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribPointervRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, void **pointer);
GL_APICALL void GL_APIENTRY glReadPixelsRobustANGLE (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLsizei *length, GLsizei *columns, GLsizei *rows, void *pixels);
GL_APICALL void GL_APIENTRY glTexImage2DRobustANGLE (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
GL_APICALL void GL_APIENTRY glTexParameterfvRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, const GLfloat *params);
GL_APICALL void GL_APIENTRY glTexParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, const GLint *params);
GL_APICALL void GL_APIENTRY glTexSubImage2DRobustANGLE (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
GL_APICALL void GL_APIENTRY glTexImage3DRobustANGLE (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
GL_APICALL void GL_APIENTRY glTexSubImage3DRobustANGLE (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, const void *pixels);
GL_APICALL void GL_APIENTRY glCompressedTexImage2DRobustANGLE(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLsizei bufSize, const void *data);
GL_APICALL void GL_APIENTRY glCompressedTexSubImage2DRobustANGLE(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLsizei bufSize, const void *data);
GL_APICALL void GL_APIENTRY glCompressedTexImage3DRobustANGLE(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLsizei bufSize, const void *data);
GL_APICALL void GL_APIENTRY glCompressedTexSubImage3DRobustANGLE(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLsizei bufSize, const void *data);
GL_APICALL void GL_APIENTRY glGetQueryivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetQueryObjectuivRobustANGLE (GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glGetBufferPointervRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, void **params);
GL_APICALL void GL_APIENTRY glGetIntegeri_vRobustANGLE (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLint *data);
GL_APICALL void GL_APIENTRY glGetInternalformativRobustANGLE (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribIivRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetVertexAttribIuivRobustANGLE (GLuint index, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glGetUniformuivRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glGetActiveUniformBlockivRobustANGLE (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetInteger64vRobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *data);
GL_APICALL void GL_APIENTRY glGetInteger64i_vRobustANGLE (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLint64 *data);
GL_APICALL void GL_APIENTRY glGetBufferParameteri64vRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *params);
GL_APICALL void GL_APIENTRY glSamplerParameterivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, const GLint *param);
GL_APICALL void GL_APIENTRY glSamplerParameterfvRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, const GLfloat *param);
GL_APICALL void GL_APIENTRY glGetSamplerParameterivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetSamplerParameterfvRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetFramebufferParameterivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetProgramInterfaceivRobustANGLE (GLuint program, GLenum programInterface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetBooleani_vRobustANGLE (GLenum target, GLuint index, GLsizei bufSize, GLsizei *length, GLboolean *data);
GL_APICALL void GL_APIENTRY glGetMultisamplefvRobustANGLE (GLenum pname, GLuint index, GLsizei bufSize, GLsizei *length, GLfloat *val);
GL_APICALL void GL_APIENTRY glGetTexLevelParameterivRobustANGLE (GLenum target, GLint level, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetTexLevelParameterfvRobustANGLE (GLenum target, GLint level, GLenum pname, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetPointervRobustANGLERobustANGLE (GLenum pname, GLsizei bufSize, GLsizei *length, void **params);
GL_APICALL void GL_APIENTRY glReadnPixelsRobustANGLE (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLsizei *length, GLsizei *columns, GLsizei *rows, void *data);
GL_APICALL void GL_APIENTRY glGetnUniformfvRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetnUniformivRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetnUniformuivRobustANGLE (GLuint program, GLint location, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glTexParameterIivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, const GLint *params);
GL_APICALL void GL_APIENTRY glTexParameterIuivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, const GLuint *params);
GL_APICALL void GL_APIENTRY glGetTexParameterIivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetTexParameterIuivRobustANGLE (GLenum target, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glSamplerParameterIivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, const GLint *param);
GL_APICALL void GL_APIENTRY glSamplerParameterIuivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, const GLuint *param);
GL_APICALL void GL_APIENTRY glGetSamplerParameterIivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetSamplerParameterIuivRobustANGLE (GLuint sampler, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint *params);
GL_APICALL void GL_APIENTRY glGetQueryObjectivRobustANGLE(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *params);
GL_APICALL void GL_APIENTRY glGetQueryObjecti64vRobustANGLE(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLint64 *params);
GL_APICALL void GL_APIENTRY glGetQueryObjectui64vRobustANGLE(GLuint id, GLenum pname, GLsizei bufSize, GLsizei *length, GLuint64 *params);
#endif
#endif /* GL_ANGLE_robust_client_memory */

#ifndef GL_ANGLE_program_cache_control
#define GL_ANGLE_program_cache_control 1
#define GL_PROGRAM_CACHE_ENABLED_ANGLE 0x93AC
#endif  /* GL_ANGLE_program_cache_control */

#ifndef GL_ANGLE_texture_rectangle
#define GL_ANGLE_texture_rectangle 1
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ANGLE 0x84F8
#define GL_TEXTURE_RECTANGLE_ANGLE 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ANGLE 0x84F6
#define GL_SAMPLER_2D_RECT_ANGLE 0x8B63
#endif /* GL_ANGLE_texture_rectangle */

#ifndef GL_ANGLE_texture_multisample
#define GL_ANGLE_texture_multisample 1
#define GL_SAMPLE_POSITION_ANGLE 0x8E50
#define GL_SAMPLE_MASK_ANGLE 0x8E51
#define GL_SAMPLE_MASK_VALUE_ANGLE 0x8E52
#define GL_TEXTURE_2D_MULTISAMPLE_ANGLE 0x9100
#define GL_MAX_SAMPLE_MASK_WORDS_ANGLE 0x8E59
#define GL_MAX_COLOR_TEXTURE_SAMPLES_ANGLE 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES_ANGLE 0x910F
#define GL_MAX_INTEGER_SAMPLES_ANGLE 0x9110
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ANGLE 0x9104
#define GL_TEXTURE_SAMPLES_ANGLE 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS_ANGLE 0x9107
typedef void(GL_APIENTRYP PFNGLTEXSTORAGE2DMULTISAMPLEANGLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef void(GL_APIENTRYP PFNGLGETTEXLEVELPARAMETERFVANGLEPROC)(GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void(GL_APIENTRYP PFNGLGETTEXLEVELPARAMETERIVANGLEPROC)(GLenum target, GLint level, GLenum pname, GLint *params);
typedef void (GL_APIENTRYP PFNGLGETMULTISAMPLEFVANGLEPROC)(GLenum pname, GLuint index, GLfloat *val);
typedef void (GL_APIENTRYP PFNGLSAMPLEMASKIANGLEPROC)(GLuint maskNumber, GLbitfield mask);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glTexStorage2DMultisampleANGLE(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GL_APICALL void GL_APIENTRY glGetTexLevelParameterfvANGLE(GLenum target, GLint level, GLenum pname, GLfloat *params);
GL_APICALL void GL_APIENTRY glGetTexLevelParameterivANGLE(GLenum target, GLint level, GLenum pname, GLint *params);
GL_APICALL void GL_APIENTRY glGetMultisamplefvANGLE(GLenum pname, GLuint index, GLfloat *val);
GL_APICALL void GL_APIENTRY glSampleMaskiANGLE(GLuint maskNumber, GLbitfield mask);
#endif
#endif  // !GL_ANGLE_texture_multisample

#ifndef GL_ANGLE_explicit_context
#define GL_ANGLE_explicit_context
typedef void *GLeglContext;
#include "gl2ext_explicit_context_autogen.inc"
#include "../GLES3/gl3ext_explicit_context_autogen.inc"
#include "../GLES3/gl31ext_explicit_context_autogen.inc"
#include "../GLES3/gl32.h"
#include "../GLES3/gl32ext_explicit_context_autogen.inc"
#endif /* GL_ANGLE_explicit_context */

#ifndef GL_ANGLE_multi_draw
#define GL_ANGLE_multi_draw 1
typedef void (GL_APIENTRYP PFNGLMULTIDRAWARRAYSANGLEPROC) (GLenum mode, const GLint *firsts, const GLsizei *counts, GLsizei drawcount);
typedef void (GL_APIENTRYP PFNGLMULTIDRAWARRAYSINSTANCEDANGLEPROC) (GLenum mode, const GLint *firsts, const GLsizei *counts, const GLsizei *instanceCounts, GLsizei drawcount);
typedef void (GL_APIENTRYP PFNGLMULTIDRAWELEMENTSANGLEPROC) (GLenum mode, const GLsizei *counts, GLenum type, const GLvoid* const *indices, GLsizei drawcount);
typedef void (GL_APIENTRYP PFNGLMULTIDRAWELEMENTSINSTANCEDANGLEPROC) (GLenum mode, const GLsizei *counts, GLenum type, const GLvoid* const *indices, const GLsizei *instanceCounts, GLsizei drawcount);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glMultiDrawArraysANGLE (GLenum mode, const GLint *firsts, const GLsizei *counts, GLsizei drawcount);
GL_APICALL void GL_APIENTRY glMultiDrawArraysInstancedANGLE (GLenum mode, const GLint *firsts, const GLsizei *counts, const GLsizei *instanceCounts, GLsizei drawcount);
GL_APICALL void GL_APIENTRY glMultiDrawElementsANGLE (GLenum mode, const GLsizei *counts, GLenum type, const GLvoid* const *indices, GLsizei drawcount);
GL_APICALL void GL_APIENTRY glMultiDrawElementsInstancedANGLE (GLenum mode, const GLsizei *counts, GLenum type, const GLvoid* const *indices, const GLsizei *instanceCounts, GLsizei drawcount);
#endif
#endif /* GL_ANGLE_multi_draw */

#ifndef GL_ANGLE_base_vertex_base_instance
#define GL_ANGLE_base_vertex_base_instance 1
typedef void (GL_APIENTRYP PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEANGLEPROC) (GLenum mode, GLint first, GLsizei count, GLsizei instanceCount, GLuint baseInstance);
typedef void (GL_APIENTRYP PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEANGLEPROC) (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instanceCount, GLint baseVertex, GLuint baseInstance);
typedef void (GL_APIENTRYP PFNGLMULTIDRAWARRAYSINSTANCEDBASEINSTANCEANGLEPROC) (GLenum mode, const GLsizei *firsts, const GLsizei *counts, const GLsizei *instanceCounts, const GLuint *baseInstances, GLsizei drawCount);
typedef void (GL_APIENTRYP PFNGLMULTIDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEANGLEPROC) (GLenum mode, const GLsizei *counts, GLenum type, const GLvoid* const *indices, const GLsizei *instanceCounts, const GLint *baseVertices, const GLuint *baseInstances, GLsizei drawCount);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glDrawArraysInstancedBaseInstanceANGLE (GLenum mode, GLint first, GLsizei count, GLsizei instanceCount, GLuint baseInstance);
GL_APICALL void GL_APIENTRY glDrawElementsInstancedBaseVertexBaseInstanceANGLE (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instanceCount, GLint baseVertex, GLuint baseInstance);
GL_APICALL void GL_APIENTRY glMultiDrawArraysInstancedBaseInstanceANGLE (GLenum mode, const GLsizei *firsts, const GLsizei *counts, const GLsizei *instanceCounts, const GLuint *baseInstances, GLsizei drawCount);
GL_APICALL void GL_APIENTRY glMultiDrawElementsInstancedBaseVertexBaseInstanceANGLE (GLenum mode, const GLsizei *counts, GLenum type, const GLvoid* const *indices, const GLsizei *instanceCounts, const GLint *baseVertices, const GLuint *baseInstances, GLsizei drawCount);
#endif
#endif

#ifndef GL_CHROMIUM_bind_uniform_location
#define GL_CHROMIUM_bind_uniform_location 1
typedef void (GL_APIENTRYP PFNGLBINDUNIFORMLOCATIONCHROMIUMPROC)(GLuint program, GLint location, const GLchar *name);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glBindUniformLocationCHROMIUM(GLuint program, GLint location, const GLchar *name);
#endif
#endif /* GL_CHROMIUM_bind_uniform_location */

/* GL_CHROMIUM_lose_context */
#ifndef GL_CHROMIUM_lose_context
#define GL_CHROMIUM_lose_context 1
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glLoseContextCHROMIUM(GLenum current, GLenum other);
#endif
typedef void (GL_APIENTRYP PFNGLLOSECONTEXTCHROMIUMPROC) (GLenum current, GLenum other);
#endif  /* GL_CHROMIUM_lose_context */

#ifndef GL_ANGLE_texture_external_update
#define GL_ANGLE_texture_external_update 1
#define GL_TEXTURE_NATIVE_ID_ANGLE 0x3481
typedef void (GL_APIENTRYP PFNGLTEXIMAGE2DEXTERNALANGLEPROC) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type);
typedef void (GL_APIENTRYP PFNGLINVALIDATETEXTUREANGLEPROC) (GLenum target);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glTexImage2DExternalANGLE (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type);
GL_APICALL void GL_APIENTRY glInvalidateTextureANGLE (GLenum target);
#endif
#endif /* GL_ANGLE_texture_external_update */

#ifndef GL_ANGLE_get_image
#define GL_ANGLE_get_image
typedef void (GL_APIENTRYP PFNGLGETTEXIMAGEANGLEPROC) (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
typedef void (GL_APIENTRYP PFNGLGETRENDERBUFFERIMAGEANGLEPROC) (GLenum target, GLenum format, GLenum type, void *pixels);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glGetTexImageANGLE (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GL_APICALL void GL_APIENTRY glGetRenderbufferImageANGLE (GLenum target, GLenum format, GLenum type, void *pixels);
#endif
#endif /* GL_ANGLE_texture_external_update */

#ifndef GL_WEBGL_video_texture
#define GL_WEBGL_video_texture 1
#define GL_TEXTURE_VIDEO_IMAGE_WEBGL 0x9248
#define GL_SAMPLER_VIDEO_IMAGE_WEBGL 0x9249
#endif /* GL_WEBGL_video_texture */

#ifndef GL_ANGLE_memory_object_fuchsia
#define GL_ANGLE_memory_object_fuchsia 1
#define GL_HANDLE_TYPE_ZIRCON_VMO_ANGLE 0x93AE
typedef void(GL_APIENTRYP PFNGLIMPORTMEMORYZIRCONHANDLEANGLEPROC)(GLuint memory,
                                                                  GLuint64 size,
                                                                  GLenum handleType,
                                                                  GLuint handle);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glImportMemoryZirconHandleANGLE(GLuint memory,
                                                            GLuint64 size,
                                                            GLenum handleType,
                                                            GLuint handle);
#endif
#endif /* GL_ANGLE_memory_object_fuchsia */

#ifndef GL_ANGLE_semaphore_fuchsia
#define GL_ANGLE_semaphore_fuchsia 1
#define GL_HANDLE_TYPE_ZIRCON_EVENT_ANGLE 0x93AF
typedef void(GL_APIENTRYP PFNGLIMPORTSEMAPHOREZIRCONHANDLEANGLEPROC)(GLuint semaphore,
                                                                     GLenum handleType,
                                                                     GLuint handle);
#ifdef GL_GLEXT_PROTOTYPES
GL_APICALL void GL_APIENTRY glImportSemaphoreZirconHandleANGLE(GLuint memory,
                                                               GLenum handleType,
                                                               GLuint handle);
#endif
#endif /* GL_ANGLE_semaphore_fuchsia */

// clang-format on

#endif  // INCLUDE_GLES2_GL2EXT_ANGLE_H_
