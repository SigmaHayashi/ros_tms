// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.
#ifndef __Tag_hh__
#define __Tag_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef USE_stub_in_nt_dll
#define USE_stub_in_nt_dll_NOT_DEFINED_Tag
#endif
#ifndef USE_core_stub_in_nt_dll
#define USE_core_stub_in_nt_dll_NOT_DEFINED_Tag
#endif
#ifndef USE_dyn_stub_in_nt_dll
#define USE_dyn_stub_in_nt_dll_NOT_DEFINED_Tag
#endif

#ifdef USE_stub_in_nt_dll
#ifndef USE_core_stub_in_nt_dll
#define USE_core_stub_in_nt_dll
#endif
#ifndef USE_dyn_stub_in_nt_dll
#define USE_dyn_stub_in_nt_dll
#endif
#endif

#ifdef _core_attr
#error "A local CPP macro _core_attr has already been defined."
#else
#ifdef USE_core_stub_in_nt_dll
#define _core_attr _OMNIORB_NTDLL_IMPORT
#else
#define _core_attr
#endif
#endif

#ifdef _dyn_attr
#error "A local CPP macro _dyn_attr has already been defined."
#else
#ifdef USE_dyn_stub_in_nt_dll
#define _dyn_attr _OMNIORB_NTDLL_IMPORT
#else
#define _dyn_attr
#endif
#endif

class TagData_var;

class TagData : public _CORBA_Unbounded_Sequence_Octet
{
public:
  typedef TagData_var _var_type;
  inline TagData()
  {
  }
  inline TagData(const TagData& _s) : _CORBA_Unbounded_Sequence_Octet(_s)
  {
  }

  inline TagData(_CORBA_ULong _max) : _CORBA_Unbounded_Sequence_Octet(_max)
  {
  }
  inline TagData(_CORBA_ULong _max, _CORBA_ULong _len, ::CORBA::Octet* _val, _CORBA_Boolean _rel = 0)
    : _CORBA_Unbounded_Sequence_Octet(_max, _len, _val, _rel)
  {
  }

  inline TagData& operator=(const TagData& _s)
  {
    _CORBA_Unbounded_Sequence_Octet::operator=(_s);
    return *this;
  }
};

class TagData_out;

class TagData_var
{
public:
  inline TagData_var() : _pd_seq(0)
  {
  }
  inline TagData_var(TagData* _s) : _pd_seq(_s)
  {
  }
  inline TagData_var(const TagData_var& _s)
  {
    if (_s._pd_seq)
      _pd_seq = new TagData(*_s._pd_seq);
    else
      _pd_seq = 0;
  }
  inline ~TagData_var()
  {
    if (_pd_seq)
      delete _pd_seq;
  }

  inline TagData_var& operator=(TagData* _s)
  {
    if (_pd_seq)
      delete _pd_seq;
    _pd_seq = _s;
    return *this;
  }
  inline TagData_var& operator=(const TagData_var& _s)
  {
    if (_s._pd_seq)
    {
      if (!_pd_seq)
        _pd_seq = new TagData;
      *_pd_seq = *_s._pd_seq;
    }
    else if (_pd_seq)
    {
      delete _pd_seq;
      _pd_seq = 0;
    }
    return *this;
  }
  inline ::CORBA::Octet& operator[](_CORBA_ULong _s)
  {
    return (*_pd_seq)[_s];
  }

  inline TagData* operator->()
  {
    return _pd_seq;
  }
  inline const TagData* operator->() const
  {
    return _pd_seq;
  }
#if defined(__GNUG__)
  inline operator TagData&() const
  {
    return *_pd_seq;
  }
#else
  inline operator const TagData&() const
  {
    return *_pd_seq;
  }
  inline operator TagData&()
  {
    return *_pd_seq;
  }
#endif

  inline const TagData& in() const
  {
    return *_pd_seq;
  }
  inline TagData& inout()
  {
    return *_pd_seq;
  }
  inline TagData*& out()
  {
    if (_pd_seq)
    {
      delete _pd_seq;
      _pd_seq = 0;
    }
    return _pd_seq;
  }
  inline TagData* _retn()
  {
    TagData* tmp = _pd_seq;
    _pd_seq = 0;
    return tmp;
  }

  friend class TagData_out;

private:
  TagData* _pd_seq;
};

class TagData_out
{
public:
  inline TagData_out(TagData*& _s) : _data(_s)
  {
    _data = 0;
  }
  inline TagData_out(TagData_var& _s) : _data(_s._pd_seq)
  {
    _s = (TagData*)0;
  }
  inline TagData_out(const TagData_out& _s) : _data(_s._data)
  {
  }
  inline TagData_out& operator=(const TagData_out& _s)
  {
    _data = _s._data;
    return *this;
  }
  inline TagData_out& operator=(TagData* _s)
  {
    _data = _s;
    return *this;
  }
  inline operator TagData*&()
  {
    return _data;
  }
  inline TagData*& ptr()
  {
    return _data;
  }
  inline TagData* operator->()
  {
    return _data;
  }

  inline ::CORBA::Octet& operator[](_CORBA_ULong _i)
  {
    return (*_data)[_i];
  }

  TagData*& _data;

private:
  TagData_out();
  TagData_out& operator=(const TagData_var&);
};

_CORBA_MODULE Tag

    _CORBA_MODULE_BEG

#ifndef __Tag_mReaderWriter__
#define __Tag_mReaderWriter__

    class ReaderWriter;
class _objref_ReaderWriter;
class _impl_ReaderWriter;

typedef _objref_ReaderWriter* ReaderWriter_ptr;
typedef ReaderWriter_ptr ReaderWriterRef;

class ReaderWriter_Helper
{
public:
  typedef ReaderWriter_ptr _ptr_type;

  static _ptr_type _nil();
  static _CORBA_Boolean is_nil(_ptr_type);
  static void release(_ptr_type);
  static void duplicate(_ptr_type);
  static void marshalObjRef(_ptr_type, cdrStream&);
  static _ptr_type unmarshalObjRef(cdrStream&);
};

typedef _CORBA_ObjRef_Var< _objref_ReaderWriter, ReaderWriter_Helper > ReaderWriter_var;
typedef _CORBA_ObjRef_OUT_arg< _objref_ReaderWriter, ReaderWriter_Helper > ReaderWriter_out;

#endif

// interface ReaderWriter
class ReaderWriter
{
public:
  // Declarations for this interface type.
  typedef ReaderWriter_ptr _ptr_type;
  typedef ReaderWriter_var _var_type;

  static _ptr_type _duplicate(_ptr_type);
  static _ptr_type _narrow(::CORBA::Object_ptr);
  static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);

  static _ptr_type _nil();

  static inline void _marshalObjRef(_ptr_type, cdrStream&);

  static inline _ptr_type _unmarshalObjRef(cdrStream& s)
  {
    omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId, s);
    if (o)
      return (_ptr_type)o->_ptrToObjRef(_PD_repoId);
    else
      return _nil();
  }

  static _core_attr const char* _PD_repoId;

  // Other IDL defined within this scope.
};

class _objref_ReaderWriter : public virtual ::CORBA::Object, public virtual omniObjRef
{
public:
  ::CORBA::Boolean intialize();
  ::CORBA::Boolean setConfig(::CORBA::Long confNo, ::CORBA::Long confVal);
  ::CORBA::Long getConfig(::CORBA::Long confNo);
  ::CORBA::Boolean setupCom(::CORBA::ULong baud, ::CORBA::ULong stop, ::CORBA::ULong parity);
  ::CORBA::Boolean RFPowerOff();
  ::CORBA::Boolean setPower(::CORBA::Long power);
  ::CORBA::Long getPower();
  ::CORBA::Long getNoiseLevel();
  ::CORBA::Boolean tagReset();
  ::CORBA::Boolean inventory(::TagData_out uids);
  ::CORBA::Boolean ISORead(::CORBA::Long blockAddr, ::CORBA::Long blockNum, ::TagData_out data, const ::TagData& uid);
  ::CORBA::Boolean ISOWrite(::CORBA::Long blockAddr, ::CORBA::Long blockNum, const ::TagData& data,
                            const ::TagData& uid);
  ::CORBA::Boolean ISOStayQuiet(const ::TagData& uid);
  ::CORBA::Boolean ISOResetToReady(const ::TagData& uid);
  ::CORBA::Boolean senseTag(::CORBA::Long& kind);
  ::CORBA::Boolean stop(::CORBA::Long cmdClass);
  ::CORBA::ULong CommPort();
  void CommPort(::CORBA::ULong _v);
  ::CORBA::Boolean isPortOpen();
  void isPortOpen(::CORBA::Boolean _v);
  ::CORBA::ULong BaudRate();
  void BaudRate(::CORBA::ULong _v);
  ::CORBA::ULong Parity();
  void Parity(::CORBA::ULong _v);
  ::CORBA::ULong Stopbits();
  void Stopbits(::CORBA::ULong _v);
  char* IPAddress();
  void IPAddress(const char* _v);
  ::CORBA::ULong ServerPort();
  void ServerPort(::CORBA::ULong _v);
  ::CORBA::Boolean isConnect();
  void isConnect(::CORBA::Boolean _v);
  ::CORBA::Double RecvTimeOut();
  void RecvTimeOut(::CORBA::Double _v);
  ::CORBA::Long LastStatus();
  void LastStatus(::CORBA::Long _v);

  inline _objref_ReaderWriter()
  {
    _PR_setobj(0);
  }  // nil
  _objref_ReaderWriter(omniIOR*, omniIdentity*);

protected:
  virtual ~_objref_ReaderWriter();

private:
  virtual void* _ptrToObjRef(const char*);

  _objref_ReaderWriter(const _objref_ReaderWriter&);
  _objref_ReaderWriter& operator=(const _objref_ReaderWriter&);
  // not implemented

  friend class ReaderWriter;
};

class _pof_ReaderWriter : public _OMNI_NS(proxyObjectFactory)
{
public:
  inline _pof_ReaderWriter() : _OMNI_NS(proxyObjectFactory)(ReaderWriter::_PD_repoId)
  {
  }
  virtual ~_pof_ReaderWriter();

  virtual omniObjRef* newObjRef(omniIOR*, omniIdentity*);
  virtual _CORBA_Boolean is_a(const char*) const;
};

class _impl_ReaderWriter : public virtual omniServant
{
public:
  virtual ~_impl_ReaderWriter();

  virtual ::CORBA::Boolean intialize() = 0;
  virtual ::CORBA::Boolean setConfig(::CORBA::Long confNo, ::CORBA::Long confVal) = 0;
  virtual ::CORBA::Long getConfig(::CORBA::Long confNo) = 0;
  virtual ::CORBA::Boolean setupCom(::CORBA::ULong baud, ::CORBA::ULong stop, ::CORBA::ULong parity) = 0;
  virtual ::CORBA::Boolean RFPowerOff() = 0;
  virtual ::CORBA::Boolean setPower(::CORBA::Long power) = 0;
  virtual ::CORBA::Long getPower() = 0;
  virtual ::CORBA::Long getNoiseLevel() = 0;
  virtual ::CORBA::Boolean tagReset() = 0;
  virtual ::CORBA::Boolean inventory(::TagData_out uids) = 0;
  virtual ::CORBA::Boolean ISORead(::CORBA::Long blockAddr, ::CORBA::Long blockNum, ::TagData_out data,
                                   const ::TagData& uid) = 0;
  virtual ::CORBA::Boolean ISOWrite(::CORBA::Long blockAddr, ::CORBA::Long blockNum, const ::TagData& data,
                                    const ::TagData& uid) = 0;
  virtual ::CORBA::Boolean ISOStayQuiet(const ::TagData& uid) = 0;
  virtual ::CORBA::Boolean ISOResetToReady(const ::TagData& uid) = 0;
  virtual ::CORBA::Boolean senseTag(::CORBA::Long& kind) = 0;
  virtual ::CORBA::Boolean stop(::CORBA::Long cmdClass) = 0;
  virtual ::CORBA::ULong CommPort() = 0;
  virtual void CommPort(::CORBA::ULong _v) = 0;
  virtual ::CORBA::Boolean isPortOpen() = 0;
  virtual void isPortOpen(::CORBA::Boolean _v) = 0;
  virtual ::CORBA::ULong BaudRate() = 0;
  virtual void BaudRate(::CORBA::ULong _v) = 0;
  virtual ::CORBA::ULong Parity() = 0;
  virtual void Parity(::CORBA::ULong _v) = 0;
  virtual ::CORBA::ULong Stopbits() = 0;
  virtual void Stopbits(::CORBA::ULong _v) = 0;
  virtual char* IPAddress() = 0;
  virtual void IPAddress(const char* _v) = 0;
  virtual ::CORBA::ULong ServerPort() = 0;
  virtual void ServerPort(::CORBA::ULong _v) = 0;
  virtual ::CORBA::Boolean isConnect() = 0;
  virtual void isConnect(::CORBA::Boolean _v) = 0;
  virtual ::CORBA::Double RecvTimeOut() = 0;
  virtual void RecvTimeOut(::CORBA::Double _v) = 0;
  virtual ::CORBA::Long LastStatus() = 0;
  virtual void LastStatus(::CORBA::Long _v) = 0;

public:  // Really protected, workaround for xlC
  virtual _CORBA_Boolean _dispatch(omniCallHandle&);

private:
  virtual void* _ptrToInterface(const char*);
  virtual const char* _mostDerivedRepoId();
};

_CORBA_MODULE_END

_CORBA_MODULE POA_Tag _CORBA_MODULE_BEG

    class ReaderWriter : public virtual Tag::_impl_ReaderWriter,
                         public virtual ::PortableServer::ServantBase
{
public:
  virtual ~ReaderWriter();

  inline ::Tag::ReaderWriter_ptr _this()
  {
    return (::Tag::ReaderWriter_ptr)_do_this(::Tag::ReaderWriter::_PD_repoId);
  }
};

_CORBA_MODULE_END

_CORBA_MODULE OBV_Tag _CORBA_MODULE_BEG

    _CORBA_MODULE_END

#undef _core_attr
#undef _dyn_attr

    inline void
    Tag::ReaderWriter::_marshalObjRef(::Tag::ReaderWriter_ptr obj, cdrStream& s)
{
  omniObjRef::_marshal(obj->_PR_getobj(), s);
}

#ifdef USE_stub_in_nt_dll_NOT_DEFINED_Tag
#undef USE_stub_in_nt_dll
#undef USE_stub_in_nt_dll_NOT_DEFINED_Tag
#endif
#ifdef USE_core_stub_in_nt_dll_NOT_DEFINED_Tag
#undef USE_core_stub_in_nt_dll
#undef USE_core_stub_in_nt_dll_NOT_DEFINED_Tag
#endif
#ifdef USE_dyn_stub_in_nt_dll_NOT_DEFINED_Tag
#undef USE_dyn_stub_in_nt_dll
#undef USE_dyn_stub_in_nt_dll_NOT_DEFINED_Tag
#endif

#endif  // __Tag_hh__
