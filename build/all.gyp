{
  'make_global_settings': [
    ['CXX','/usr/local/develop/c++11/clang3.3/bin/clang++'],
    ['LINK','/usr/local/develop/c++11/clang3.3/bin/clang++'],
  ],
  'target_defaults': {
    'conditions': [
      ['OS=="linux"', {
        'defines': [
          'LINUX_DEFINE',
        ],
        'include_dirs': [
        ],
      }],
      ['OS=="win"', {
        'defines': [
          'WINDOWS_SPECIFIC_DEFINE',
        ],
      }, { # OS != "win",
        'defines': [
          'NON_WINDOWS_DEFINE',
        ],
        'include_dirs': [
          '/usr/local/develop/c++11/libcxx-3.3/include/',
        ],
        'xcode_settings': {
          'OTHER_CPLUSPLUSFLAGS' : ['-std=c++11','-stdlib=libc++'],
          'OTHER_LDFLAGS': ['-stdlib=libc++'],
        },
      }]
    ],
  },
  'targets': [
    {
      'target_name': 'auto',
      'type': 'executable',
      'sources': [
        '../src/auto.cpp',
      ],
    },
    {
      'target_name': 'for',
      'type': 'executable',
      'sources': [
        '../src/for.cpp',
      ],
    },
    {
      'target_name': 'lambda',
      'type': 'executable',
      'sources': [
        '../src/lambda.cpp',
      ],
    },
  ],
}