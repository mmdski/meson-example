project(
    'example',
    'c',
    default_options: {'warning_level': '3', 'werror': true},
    meson_version: '>=1.4.0',
    version: '0.1.0',
)
add_project_arguments('-pedantic', '-Wconversion', language: 'c')

executable('hello', 'src/main.c')

cc = meson.get_compiler('c')

test_env = environment()
test_env.set('ASAN_OPTIONS', 'abort_on_error=0')
if cc.has_argument('-fsanitize=leak')
    test_env.append('ASAN_OPTIONS', 'detect_leaks=1')

    lsan_suppressions = files('lsan.supp')
    test_env.set(
        'LSAN_OPTIONS',
        'suppressions=@0@'.format(lsan_suppressions[0].full_path()),
    )
endif

no_leak_exe = executable('mem_no_leak', 'src/mem_no_leak.c')
test('mem_no_leak', no_leak_exe, env: test_env)

leak_exe = executable('mem_leak', 'src/mem_leak.c')
test('mem_leak', leak_exe, env: test_env, should_fail: true)

ub_exe = executable('ub', sources: 'src/ub-test.c')
test('ub', ub_exe, env: test_env, should_fail: true)
