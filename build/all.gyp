{
  'make_global_settings': [
    ['CXX','/usr/local/develop/c++11/clang3.3/bin/clang++'],
    ['LINK','/usr/local/develop/c++11/clang3.3/bin/clang++'],
  ],
  'targets': [
    {
      'target_name': 'auto',
      'type': 'executable',
      'msvs_guid': '5ECEC9E5-8F23-47B6-93E0-C3B328B3BE65',
      'dependencies': [],
      'defines': [
        'DEFINE_FOO',
        'DEFINE_A_VALUE=value',
      ],
      'include_dirs': [],
      'sources': [
        '../src/auto.cpp',
      ],
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

    {
      'target_name': 'for',
      'type': 'executable',
      'msvs_guid': '5ECEC9E5-8F23-47B6-93E0-C3B328B3BE65',
      'dependencies': [],
      'defines': [
        'DEFINE_FOO',
        'DEFINE_A_VALUE=value',
      ],
      'include_dirs': [],
      'sources': [
        '../src/for.cpp',
      ],
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
  ],
}