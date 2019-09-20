var gulp = require('gulp');
var sass = require('gulp-sass');
var uglifyjs = require('gulp-uglify');
var babel = require("gulp-babel");
var clean = require('gulp-rimraf');
var path = require('path');
var uglifycss = require('gulp-uglifycss');
var concat = require('gulp-concat');
var runSequence = require('run-sequence');
var jade = require('gulp-jade');


var targetDirectory = 'target/',
  styleSrcs = 'src/public/angularApp/**/*.scss',
  styleTarget = targetDirectory + 'public/css';


gulp.task('clean', () => {
  gulp.src(targetDirectory)
    .pipe(clean());
});

gulp.task('sass', () => {
  gulp.src(styleSrcs)
    .pipe(sass())
    .pipe(concat('style.min.css'))
    .pipe(uglifycss())
    .pipe(gulp.dest(styleTarget));
});

gulp.task('assets', () => {
  gulp.src(['src/public/assets/**/*'], { base: 'src/' })
    .pipe(gulp.dest(targetDirectory));
});

gulp.task('jade', () => {
  gulp.src('src/**/*.jade', { base: 'src' })
    .pipe(jade())
    .pipe(gulp.dest(targetDirectory));
});


gulp.task('babel', () => {
  gulp.src(['src/public/angularApp/**/*.js']) // angular
    //.pipe(sourcemaps.init())
    .pipe(babel())
    .pipe(concat('app.min.js'))
    //.pipe(sourcemaps.write("."))
    //.pipe(uglifyjs({mangle: false}))
    .pipe(gulp.dest('target/public/angularApp'));

  gulp.src(['src/**/*.js', '!src/public/**/*']) // node
    //.pipe(sourcemaps.init())
    .pipe(babel())
    //.pipe(sourcemaps.write("."))
    //.pipe(uglifyjs({mangle: false}))
    .pipe(gulp.dest(targetDirectory));
});

gulp.task('build', ['assets', 'babel', 'sass', 'jade']);

gulp.task('watch', ['build'], () => {
  gulp.watch('src/**/*', ['babel', 'sass', 'jade']);
});
gulp.task('default', ['watch'], () => { });
