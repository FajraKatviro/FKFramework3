
#if defined(FK_NET_LIBRARY)
#  define FK_NET_EXPORT Q_DECL_EXPORT
#else
#  define FK_NET_EXPORT Q_DECL_IMPORT
#endif
