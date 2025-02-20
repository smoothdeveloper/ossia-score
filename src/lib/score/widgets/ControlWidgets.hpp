#pragma once
#include <score/widgets/DoubleSlider.hpp>
#include <score/widgets/IntSlider.hpp>

#include <QPushButton>

#include <score_lib_base_export.h>

#include <array>
namespace score
{
struct SCORE_LIB_BASE_EXPORT ToggleButton : public QPushButton
{
public:
  ToggleButton(std::array<QString, 2> alts, QWidget* parent);

  ToggleButton(std::array<const char*, 2> alt, QWidget* parent);

  ToggleButton(QStringList alt, QWidget* parent);
  ~ToggleButton();

  std::array<QString, 2> alternatives;

protected:
  void paintEvent(QPaintEvent* event) override;
};

struct SCORE_LIB_BASE_EXPORT ValueSlider : public score::IntSlider
{
public:
  using IntSlider::IntSlider;
  ~ValueSlider();
  bool moving = false;

protected:
  void paintEvent(QPaintEvent* event) override;
};

struct SCORE_LIB_BASE_EXPORT SpeedSlider : public score::DoubleSlider
{
public:
  explicit SpeedSlider(QWidget* parent = nullptr);
  ~SpeedSlider();
  bool moving = false;
  bool showText = true;

  double speed() const noexcept;
  void setSpeed(double);
  void setTempo(double);

protected:
  using score::DoubleSlider::setValue;
  using score::DoubleSlider::value;

  void paintEvent(QPaintEvent* event) override;
  void mousePressEvent(QMouseEvent*) override;
  void createPopup(QPoint pos);
};

struct SCORE_LIB_BASE_EXPORT VolumeSlider : public score::DoubleSlider
{
public:
  using DoubleSlider::DoubleSlider;
  ~VolumeSlider();

  bool moving = false;

protected:
  void paintEvent(QPaintEvent* event) override;
};

struct SCORE_LIB_BASE_EXPORT ValueDoubleSlider : public score::DoubleSlider
{
public:
  using score::DoubleSlider::DoubleSlider;
  ~ValueDoubleSlider();

  bool moving = false;
  double min{};
  double max{};

  void setRange(double min, double max) noexcept;

protected:
  void paintEvent(QPaintEvent* event) override;
};

struct SCORE_LIB_BASE_EXPORT ValueLogDoubleSlider : public score::DoubleSlider
{
public:
  using score::DoubleSlider::DoubleSlider;
  ~ValueLogDoubleSlider();

  bool moving = false;
  double min{};
  double max{};

  void setRange(double min, double max) noexcept;

protected:
  void paintEvent(QPaintEvent* event) override;
};

struct SCORE_LIB_BASE_EXPORT ComboSlider : public score::IntSlider
{
  QStringList array;

public:
  template <std::size_t N>
  ComboSlider(const std::array<const char*, N>& arr, QWidget* parent)
      : score::IntSlider{parent}
  {
    array.reserve(N);
    for (auto str : arr)
      array.push_back(str);
  }

  ComboSlider(const QStringList& arr, QWidget* parent);
  ~ComboSlider();

  bool moving = false;

protected:
  void paintEvent(QPaintEvent* event) override;
};

SCORE_LIB_BASE_EXPORT const QPalette& transparentPalette();
}
