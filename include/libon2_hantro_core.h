/*
 * Copyright (c) 2017 Helio Machado <crushedice2000@gmail.com>
 * 
 * libon2_hantro_core.h - OpenMax IL version 1.1.2 for Hantro x170.
 * The libon2_hantro_core header file contains the function signatures
 * for the libon2_hantro_core.so shared library, distributed along this code.
 *
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 2.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * The long comments documenting each function, are created and licensed
 * by The Khronos Group Inc. and the license terms can be found in the file
 * OMX_Core.h, which will be distributed along with this file.
 */


/* Each OMX header shall include all required header files to allow the
 *  header to compile without errors.  The includes below are required
 *  for this header file to compile successfully 
 */
#pragma once
#include <OMX_Core.h>

/** The hantro_OMX_Init method is used to initialize The hantro_OMX core.  It shall be the
    first call made into OMX and it should only be executed one time without
    an interviening OMX_Deinit call.  
    
    The core should return from this call within 20 msec.

    @return OMX_ERRORTYPE
        If the command successfully executes, the return code will be
        OMX_ErrorNone.  Otherwise the appropriate OMX error will be returned.
    @ingroup core
 */
OMX_API OMX_ERRORTYPE OMX_APIENTRY hantro_OMX_Init(void);

/** The hantro_OMX_Deinit method is used to deinitialize The hantro_OMX core.  It shall be 
    the last call made into OMX. In the event that the core determines that 
    thare are components loaded when this call is made, the core may return 
    with an error rather than try to unload the components.
        
    The core should return from this call within 20 msec.
    
    @return OMX_ERRORTYPE
        If the command successfully executes, the return code will be
        OMX_ErrorNone.  Otherwise the appropriate OMX error will be returned.
    @ingroup core
 */
OMX_API OMX_ERRORTYPE OMX_APIENTRY hantro_OMX_Deinit(void);

/** The hantro_OMX_ComponentNameEnum method will enumerate through all the names of
    recognised valid components in the system. This function is provided
    as a means to detect all the components in the system run-time. There is
    no strict ordering to the enumeration order of component names, although
    each name will only be enumerated once.  If The hantro_OMX core supports run-time
    installation of new components, it is only requried to detect newly
    installed components when the first call to enumerate component names
    is made (i.e. when nIndex is 0x0).
    
    The core should return from this call in 20 msec.
    
    @param [out] cComponentName
        pointer to a null terminated string with the component name.  The
        names of the components are strings less than 127 bytes in length
        plus the trailing null for a maximum size of 128 bytes.  An example 
        of a valid component name is "OMX.TI.AUDIO.DSP.MIXER\0".  Names are 
        assigned by the vendor, but shall start with "OMX." and then have 
        the Vendor designation next.
    @param [in] nNameLength
        number of characters in the cComponentName string.  With all 
        component name strings restricted to less than 128 characters 
        (including the trailing null) it is recomended that the caller
        provide a input string for the cComponentName of 128 characters.
    @param [in] nIndex
        number containing the enumeration index for the component. 
        Multiple calls to OMX_ComponentNameEnum with increasing values
        of nIndex will enumerate through the component names in the
        system until OMX_ErrorNoMore is returned.  The value of nIndex
        is 0 to (N-1), where N is the number of valid installed components
        in the system.
    @return OMX_ERRORTYPE
        If the command successfully executes, the return code will be
        OMX_ErrorNone.  When the value of nIndex exceeds the number of 
        components in the system minus 1, OMX_ErrorNoMore will be
        returned. Otherwise the appropriate OMX error will be returned.
    @ingroup core
 */
OMX_API OMX_ERRORTYPE OMX_APIENTRY hantro_OMX_ComponentNameEnum(
    OMX_OUT OMX_STRING cComponentName,
    OMX_IN  OMX_U32 nNameLength,
    OMX_IN  OMX_U32 nIndex);

/** The hantro_OMX_GetHandle method will locate the component specified by the
    component name given, load that component into memory and then invoke
    the component's methods to create an instance of the component.  
    
    The core should return from this call within 20 msec.
    
    @param [out] pHandle
        pointer to an OMX_HANDLETYPE pointer to be filled in by this method.
    @param [in] cComponentName
        pointer to a null terminated string with the component name.  The
        names of the components are strings less than 127 bytes in length
        plus the trailing null for a maximum size of 128 bytes.  An example 
        of a valid component name is "OMX.TI.AUDIO.DSP.MIXER\0".  Names are 
        assigned by the vendor, but shall start with "OMX." and then have 
        the Vendor designation next.
    @param [in] pAppData
        pointer to an application defined value that will be returned
        during callbacks so that the application can identify the source
        of the callback.
    @param [in] pCallBacks
        pointer to a OMX_CALLBACKTYPE structure that will be passed to the
        component to initialize it with.  
    @return OMX_ERRORTYPE
        If the command successfully executes, the return code will be
        OMX_ErrorNone.  Otherwise the appropriate OMX error will be returned.
    @ingroup core
 */
OMX_API OMX_ERRORTYPE OMX_APIENTRY hantro_OMX_GetHandle(
    OMX_OUT OMX_HANDLETYPE* pHandle, 
    OMX_IN  OMX_STRING cComponentName,
    OMX_IN  OMX_PTR pAppData,
    OMX_IN  OMX_CALLBACKTYPE* pCallBacks);

/** The hantro_OMX_FreeHandle method will free a handle allocated by The hantro_OMX_GetHandle 
    method.  If the component reference count goes to zero, the component will
    be unloaded from memory.  
    
    The core should return from this call within 20 msec when the component is 
    in The hantro_OMX_StateLoaded state.

    @param [in] hComponent
        Handle of the component to be accessed.  This is the component
        handle returned by the call to the GetHandle function.
    @return OMX_ERRORTYPE
        If the command successfully executes, the return code will be
        OMX_ErrorNone.  Otherwise the appropriate OMX error will be returned.
    @ingroup core
 */
OMX_API OMX_ERRORTYPE OMX_APIENTRY hantro_OMX_FreeHandle(
    OMX_IN  OMX_HANDLETYPE hComponent);

/** The hantro_OMX_GetComponentsOfRole method will return the number of components that support the given
    role and (if the compNames field is non-NULL) the names of those components. The call will fail if 
    an insufficiently sized array of names is supplied. To ensure the array is sufficiently sized the
    client should:
        * first call this function with the compNames field NULL to determine the number of component names
        * second call this function with the compNames field pointing to an array of names allocated 
          according to the number returned by the first call.

    The core should return from this call within 5 msec.
    
    @param [in] role
        This is generic standard component name consisting only of component class 
        name and the type within that class (e.g. 'audio_decoder.aac').
    @param [inout] pNumComps
        This is used both as input and output. 
 
        If compNames is NULL, the input is ignored and the output specifies how many components support
        the given role.
     
        If compNames is not NULL, on input it bounds the size of the input structure and 
        on output, it specifies the number of components string names listed within the compNames parameter.
    @param [inout] compNames
        If NULL this field is ignored. If non-NULL this points to an array of 128-byte strings which accepts 
        a list of the names of all physical components that implement the specified standard component name. 
        Each name is NULL terminated. numComps indicates the number of names.
    @ingroup core
 */
OMX_API OMX_ERRORTYPE hantro_OMX_GetComponentsOfRole ( 
    OMX_IN      OMX_STRING role,
    OMX_INOUT   OMX_U32 *pNumComps,
    OMX_INOUT   OMX_U8  **compNames);

/** The hantro_OMX_GetRolesOfComponent method will return the number of roles supported by the given
    component and (if the roles field is non-NULL) the names of those roles. The call will fail if 
    an insufficiently sized array of names is supplied. To ensure the array is sufficiently sized the
    client should:
        * first call this function with the roles field NULL to determine the number of role names
        * second call this function with the roles field pointing to an array of names allocated 
          according to the number returned by the first call.

    The core should return from this call within 5 msec.

    @param [in] compName
        This is the name of the component being queried about.
    @param [inout] pNumRoles
        This is used both as input and output. 
 
        If roles is NULL, the input is ignored and the output specifies how many roles the component supports.
     
        If compNames is not NULL, on input it bounds the size of the input structure and 
        on output, it specifies the number of roles string names listed within the roles parameter.
    @param [out] roles
        If NULL this field is ignored. If non-NULL this points to an array of 128-byte strings 
        which accepts a list of the names of all standard components roles implemented on the 
        specified component name. numComps indicates the number of names.
    @ingroup core
 */
OMX_API OMX_ERRORTYPE hantro_OMX_GetRolesOfComponent ( 
    OMX_IN      OMX_STRING compName, 
    OMX_INOUT   OMX_U32 *pNumRoles,
    OMX_OUT     OMX_U8 **roles);
